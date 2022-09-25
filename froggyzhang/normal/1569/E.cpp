#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int k,jb,z,pw[233];
const int d[6]={1,2,3,5,9,17};
map<int,vector<int> > mp[2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>jb>>z;
	int n=(1<<k);
	pw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=1LL*pw[i-1]*jb%mod;
	for(int i=0;i<(1<<(n/2));++i){
		int h=0;
		vector<int> A;
		for(int u=1;u<=n/2;++u){
			int g=u+n/2-1,t=k;
			while(g){
				if((i>>(g/2)&1)^(g&1))break;
				g>>=1;--t;
			}
			h=(h+1LL*u*pw[d[t]])%mod;
			A.push_back(d[t]);
		}
		mp[i&1][h]=A;
	}
	for(int i=0;i<(1<<(n/2));++i){
		int h=0;
		vector<int> A;
		for(int u=1;u<=n/2;++u){
			int g=u+n/2-1,t=k;
			while(g){
				if((i>>(g/2)&1)^(g&1))break;
				g>>=1;--t;
			}
			h=(h+1LL*(u+n/2)*pw[d[t]])%mod;
			A.push_back(d[t]);
		}
		h=(z-h+mod)%mod;
		if(mp[i&1^1].count(h)){
			auto B=mp[i&1^1][h];
			for(auto x:B)cout<<x<<' ';
			for(auto x:A)cout<<x<<' ';
			cout<<'\n';
			return 0;
		}
	}
	cout<<-1<<'\n';
	return 0;
}