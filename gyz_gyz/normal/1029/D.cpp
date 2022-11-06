#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 998244353
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,k;ll ans,a[N],w[20];
map<ll,ll>p[20];
int main(){
	scanf("%d%d",&n,&k);
	w[0]=1;rep(i,1,10)w[i]=w[i-1]*10;
	rep(i,1,n){
		scanf("%I64d",&a[i]);
		rep(j,1,10)if(w[j]>a[i]){
			if(!((w[j]%k*a[i]+a[i])%k))ans--;
			p[j][a[i]%k]++;break;
		}
	}
	rep(i,1,n)rep(j,1,10){
		if(p[j].count((k-w[j]%k*a[i]%k)%k))ans+=p[j][(k-w[j]%k*a[i]%k)%k];
	}
	printf("%I64d",ans);
}