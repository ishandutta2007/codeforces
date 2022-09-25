#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int mod=1e9+7;
int n,m,a[N],fib[N],sf[N];
set<int> S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		S.insert(a[i]);
	}
	for(int i=1;i<=n;++i){
		int x=a[i];
		while(x){
			if(x&1)x>>=1;
			else if(x%4==0)x>>=2;
			else break;
			if(S.count(x)){
				S.erase(a[i]);
				break;
			}
		}
	}
	fib[0]=fib[1]=1;
	for(int i=2;i<=m;++i){
		fib[i]=(fib[i-1]+fib[i-2])%mod;
	}
	sf[0]=fib[0];
	for(int i=1;i<=m;++i){
		sf[i]=(sf[i-1]+fib[i])%mod;
	}
	int ans=0;
	for(auto x:S){
		int z=m-__lg(x)-1;
		if(z>=0)ans=(ans+sf[z])%mod;
	}
	cout<<ans<<'\n';
	return 0;
}