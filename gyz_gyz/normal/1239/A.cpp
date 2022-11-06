#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=1e9+7;
const int inf=1e9;
int f[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	f[0]=f[1]=1;
	rep(i,2,max(n,m))f[i]=(f[i-2]+f[i-1])%mo;
	printf("%d\n",((f[n]+f[m])%mo-1+mo)%mo*2%mo);
}