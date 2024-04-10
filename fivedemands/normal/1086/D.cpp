#include<iostream>
#include<set>
using namespace std;
int n,q;
set<int>s[3];
int f[226];
int bit[3][200001];
int cur[200001];
void upd(int t,int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[t][i]+=v;
}
int qr(int t,int id){
	int res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[t][i];
	return res;
}
int cal(int id){
	int ans=0;
	int en=(id+2)%3,fr=(id+1)%3;
	if(s[en].empty()) return s[id].size();
	if(s[fr].empty() || s[id].empty()) return 0;
	int ffr=*s[fr].begin();
	int lfr=*s[fr].rbegin();
	int fen=*s[en].begin();
	int len=*s[en].rbegin();
	ans+=qr(id,min(lfr,fen));
	ans+=s[id].size()-qr(id,max(ffr,len));
	int l=max(ffr,fen),r=min(lfr,len);
	if(l<=r) ans+=qr(id,r)-qr(id,l);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	f['R']=0,f['S']=1,f['P']=2;
	cin >> n >> q;
	for(int i=1; i<=n ;i++){
		char c;
		cin >> c;
		cur[i]=f[c];
		s[cur[i]].insert(i);
		upd(cur[i],i,1);
	}
	cout << cal(0)+cal(1)+cal(2) << endl;
	for(int i=1; i<=q ;i++){
		int x;char c;cin >> x >> c;
		upd(cur[x],x,-1);
		s[cur[x]].erase(x);
		cur[x]=f[c];
		s[cur[x]].insert(x);
		upd(cur[x],x,1);
		cout << cal(0)+cal(1)+cal(2) << endl;
	}
}