#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
const int cs=26;
const int N=1e5+2;
typedef array<int,cs> acs;
int n;
acs pa[N];
acs sa[N];
acs psg[N];
acs ssg[N];
int ppg[N];
int spg[N];
string s,t;
int f(char c){return c-'a';}
int inv(int x){return n+1-x;}
void init(acs& x){for(int i=0; i<cs ;i++) x[i]=cs;}
int mex(acs& x){
	bool vis[cs];
	for(int i=0; i<cs ;i++) vis[i]=false;
	for(int i=0; i<cs ;i++) if(x[i]<cs) vis[x[i]]=true;
	for(int i=0; i<cs ;i++) if(!vis[i]) return i;
	return cs;
}
acs ord;
void build(string& p,acs* a,acs* sg,int* pg){
	for(int i=1; i<=n+1 ;i++){
		for(int j=0; j<cs ;j++) a[i][j]=a[i-1][j];
		if(i!=n+1) a[i][f(p[i])]=i;
	}
}
void solve(string& p,acs* a,acs* sg,int* pg,bool tok){
	for(int i=0; i<cs ;i++) ord[i]=i;
	for(int i=1; i<=n ;i++){
		pg[i]=pg[a[i-1][f(p[i])]]^sg[i-1][f(p[i])];
		for(int j=cs-1; j>=1 ;j--) if(ord[j]==f(p[i])) swap(ord[j-1],ord[j]);
		//if(p==s) cout << "ord: " << ord[0] << ' ' << ord[1] << endl;
		for(int j=0; j<cs ;j++){
			acs cur;init(cur);
			for(int k=0; k<j ;k++){
				if(a[i][ord[k]]>a[i][ord[j]]){
					int pr=a[i][ord[k]],pl;
					if(tok) pl=inv(sa[inv(a[i][ord[j]])][ord[k]]);
					else pl=inv(pa[inv(a[i][ord[j]])][ord[k]]);
					cur[k]=sg[i][ord[k]]^pg[pr]^pg[pl]^sg[pl-1][ord[j]];
				}
			}
			//if(p==t) cout << cur[0] << ' ' << cur[1] << ' ' << mex(cur) << endl;
			sg[i][ord[j]]=mex(cur);
		}
		//if(p==t) cout << sg[i][0] << ' ' << sg[i][1] << endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> s;n=s.size();s='?'+s+'?';
	t=s;reverse(t.begin(),t.end());
	build(s,pa,psg,ppg);build(t,sa,ssg,spg);
	solve(s,pa,psg,ppg,1);solve(t,sa,ssg,spg,0);
	int q;cin >> q;
	while(q--){
		int l,r;cin >> l >> r;
		acs cur;init(cur);
		for(int i=0; i<cs ;i++){
			int pr=pa[r][i],pl=inv(sa[inv(l)][i]);
			if(pr<l) continue;
			cur[i]=ppg[pr]^ppg[pl]^psg[r][i]^ssg[inv(l)][i];
		}
		int res=mex(cur);
		//cout << res << endl;
		if(res==0) cout << "Bob\n";
		else cout << "Alice\n";
	}
}