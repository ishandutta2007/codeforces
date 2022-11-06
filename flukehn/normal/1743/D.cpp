#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
int n;
void solve() {
	string s;
	cin>>s;
	int p;
	for(p=0;p<n;++p)if(s[p]=='1')break;
	if(p>=n) {
		cout<<"0\n";
		return;
	}
	//vector<int> q;
	//For(i,p,n) if(s[i]=='0') q.push_back(n-1-p);
	//reverse(p.begin(),p.end());
	string ret=s.substr(p, n-p);
	int fr=n+1;
	for(int i=n-1;i>=0;--i) {
		int j;
		int upd=0;
		for(j=p;j<=i;++j) {
			int k=j-i+ret.size()-1;
			dbg(i,j,k);
			if(j==p) {
				if(k<fr && s[k+p]=='0') {upd=1;break;}
				if(k>fr) {break;}
			}
			int u=max(s[j], s[j-i+n-1]);
			if(u>ret[k]) {upd=1;break;}
			if(u<ret[k]){break;}
		}
		dbg(i,fr,upd);
		if(upd) {
			ret=s.substr(p,n-p);
			//fr=p-i+ret.size()-1;
			fr=-1;
			for(int j=p;j<=i;++j) {
				int k=j-i+ret.size()-1;
				if(s[j]=='1' && ret[k]=='0') {
					ret[k]='1';
					if(fr<0) fr=k;
				}
			}
		}
	}
	cout<<ret<<"\n";
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>n){
		solve();
	}
}