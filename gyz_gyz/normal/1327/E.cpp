#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
ll p[N];
int main(){int n;
	scanf("%d",&n);p[0]=1;
	rep(i,1,n)p[i]=p[i-1]*10%mo;
	rep(i,1,n-1)printf("%lld ",(p[n-i]*18+p[n-i-1]*(n-i-1)*81)%mo);
	printf("10\n");
}