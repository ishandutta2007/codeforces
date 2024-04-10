#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define abs(x) ((x)<0?-(x):(x))
#define N 1048576
#define ll long long
#define inf 1000000000
using namespace std;
int n,m,x,ans,t,a[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&x);
		rep(i,0,31)if((1<<i)==x)a[i]++;
	}
	rep(i,1,m){
		scanf("%d",&x);ans=0;
		dep(i,31,0){
			t=x/(1<<i);if(a[i]<t)t=a[i];
			ans+=t;x-=(1<<i)*t;
		}
		if(x>0)printf("-1\n");else printf("%d\n",ans);
	}
}