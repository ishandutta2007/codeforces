#include<bits/stdc++.h>
using namespace std;
#define N 23
typedef long long ll;
const int mod=998244353;
int n,cnt[N][26],A[1<<N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		for(auto c:s){
			++cnt[i][c-'a'];
		}
	}
	for(int s=1;s<(1<<n);++s){
		static int mn[26];
		for(int j=0;j<26;++j)mn[j]=INT_MAX;
		for(int i=0;i<n;++i){
			if(s>>i&1){
				for(int j=0;j<26;++j){
					mn[j]=min(mn[j],cnt[i][j]);
				}	
			}
		}
		A[s]=__builtin_popcount(s)&1?1:mod-1;
		for(int j=0;j<26;++j){
			A[s]=1LL*A[s]*(mn[j]+1)%mod;
		}
	}
	for(int i=0;i<n;++i){
		for(int s=0;s<(1<<n);++s){
			if(s>>i&1){
				A[s]=(A[s]+A[s^(1<<i)])%mod;
			}
		}
	}
	ll ans=0;
	for(int s=1;s<(1<<n);++s){
		int ct=__builtin_popcount(s),jb=0;
		for(int i=0;i<n;++i){
			if(s>>i&1)jb+=i+1;
		}
		jb*=ct;
		ans^=1LL*jb*A[s];
	}
	cout<<ans<<'\n';
	return 0;
}