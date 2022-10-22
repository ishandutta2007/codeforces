#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+100;
typedef double db;
int X[N],Y[N];
bool cmp(int n1,int n2) {return (n1<n2);}
int abs(int x){
	if(x<0) return -x;
	return x;
}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		X[0]=Y[0]=0;
		for(int i=1;i<=2*n;i++){
			int x,y;scanf("%d%d",&x,&y);
			if(x==0) Y[++Y[0]]=abs(y);
			if(y==0) X[++X[0]]=abs(x);
		}
		sort(X+1,X+n+1,cmp);
		sort(Y+1,Y+n+1,cmp);
		db Ans=0;
		for(int i=1;i<=n;i++){
			Ans=Ans+sqrt(X[i]*1.0*X[i]+Y[i]*1.0*Y[i]);
		}
		printf("%.12lf\n",Ans);
	}
	return 0;
}