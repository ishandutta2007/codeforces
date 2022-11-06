#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1048576
#define inf 1000000000
using namespace std;
int n,d,u,ans,dis,a[N];
int main(){
	scanf("%d%d",&n,&d);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){u=1;
		rep(j,1,n){
			dis=a[i]+d-a[j];
			if(dis<0)dis=-dis;
			if((dis<d)||((dis==d)&&(i>j)))u=0;
		}
		ans+=u;u=1;
		rep(j,1,n){
			dis=a[i]-d-a[j];
			if(dis<0)dis=-dis;
			if((dis<d)||((dis==d)&&(i>j)))u=0;
		}
		ans+=u;
	}
	printf("%d\n",ans);
}