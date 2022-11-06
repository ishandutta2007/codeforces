#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
int a[N],b[N];
int main(){int n,m,p,ans=0;
	scanf("%d%d%d",&n,&m,&p);
	rep(i,0,n-1)scanf("%d",&a[i]);
	rep(i,0,m-1)scanf("%d",&b[i]);
	rep(i,0,n-1)if(a[i]%p){
		ans+=i;break;
	}
	rep(i,0,m-1)if(b[i]%p){
		ans+=i;break;
	}
	printf("%d\n",ans);
}