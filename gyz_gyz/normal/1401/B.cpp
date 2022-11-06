#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9;
const int mo=998244353;
int a[3],b[3];
void sol(){int ans=0;
	rep(i,0,2)scanf("%d",&a[i]);
	rep(i,0,2)scanf("%d",&b[i]);
	int x=min(a[2],b[1]);
	ans+=2*x;a[2]-=x;b[1]-=x;
	x=min(a[0],b[2]);
	a[0]-=x;b[2]-=x;
	x=min(a[2],b[2]);
	a[2]-=x;b[2]-=x;
	x=min(a[1],b[2]);
	ans-=2*x;a[1]-=x;b[2]-=x;
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}