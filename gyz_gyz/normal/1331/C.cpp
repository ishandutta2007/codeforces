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
int a[6];
int main(){int n,ans=0;
	scanf("%d",&n);
	rep(i,0,5)a[i]=(n>>i)&1;
	swap(a[0],a[4]);
	swap(a[2],a[3]);
	rep(i,0,5)ans+=a[i]<<i;
	printf("%d\n",ans);
}