#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 3001
using namespace std;
double a[mx][mx],s,ans;int n,t;
int main(){
	scanf("%d%lf%d",&n,&s,&t);
	a[0][0]=1;
	rep(i,0,t+1){
		rep(j,0,n-1){
			a[i+1][j+1]+=a[i][j]*s;
			a[i+1][j]+=a[i][j]*(1-s);
		}
		a[i+1][n]+=a[i][n];
	}
	rep(i,0,n)ans+=a[t][i]*i;
	printf("%lf",ans);
}