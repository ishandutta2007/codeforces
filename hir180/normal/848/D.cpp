#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[55][55];
ll modpow(ll x,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[50005],R[50005];
void make(){
	F[0] = 1;
	for(int i=1;i<50005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<50005;i++) R[i] = modpow(i,mod-2);
}
ll comb[55];
ll C(ll a,ll b){
    comb[0] = 1;
    for(int i=1;i<55;i++){
        //a+iCi+b
        comb[i] = comb[i-1]*(a+i)%mod*R[i+b]%mod;
    }
}

ll dp2[55][55];
int main(){
	int n,mm; cin >> n >> mm; make(); int m = 50;
	dp[0][1] = 1;
	dp2[0][0] = 1LL;
	for(int i=1;i<=n;i++){
		ll t[55][55]={}; 
		for(int y=0;y<=m;y++){
			for(int z=0;z<=m;z++){
				for(int a=0;a<i;a++){
						int b = i-a-1;
						t[a+b+1][min(y,z)] = (t[a+b+1][min(y,z)]+dp[a][y]*dp[b][z]%mod)%mod;
					}
				}
			}
		
		for(int a=i;a<=i;a++){
			for(int b=1;b<=m;b++){
				if(t[a][b] == 0LL) continue;
				C(t[a][b]-1,0);
				{
				for(int num=n;num>=0;num--){
				for(int fl=m;fl>=0;fl--){
					{
						if(dp2[num][fl]==0)continue;
						for(int e=1;;e++){
							if(num+e*a > n || fl+e*b > m) break;
							dp2[num+e*a][fl+e*b] += dp2[num][fl]*comb[e]%mod;
							dp2[num+e*a][fl+e*b] %= mod;
						}
					}
				}
			}
		}}}
		for(int j=2;j<=m;j++){
		
			{
				dp[i][j] = (dp[i][j]+dp2[i][j-1])%mod;
			}
		
	}}
	cout<<dp[n][mm]<<endl;
}