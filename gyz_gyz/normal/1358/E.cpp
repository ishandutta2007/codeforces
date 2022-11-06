#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
ll a[N],b[N],c[N];
int main(){int n;ll k;
	scanf("%d",&n);int m=(n+1)/2;
	rep(i,1,m)scanf("%lld",&a[i]);
	scanf("%lld",&k);
	rep(i,1,m){
		b[i]=b[i-1]+k-a[i];
		c[i]=min(c[i-1],b[i]);
	}
	ll tot=0;
	rep(i,1,m)tot+=a[i];
	rep(i,m,n){
		if(tot+c[n-i]>0){
			printf("%d\n",i);return 0;
		}tot+=k;
	}
	printf("-1\n");
}