#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define N 1010
const double eps=1e-7;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,x,y;
double g[N][N],ans[N][N];
void Guass(int n,int band,double *ans){
	for(int i=1;i<=n;++i){
		if(fabs(g[i][i])<eps){
			for(int j=i+1;j<=min(n,i+band);++j){
				if(fabs(g[j][i])>eps){
					for(int k=i;k<=min(n,i+2*band);++k){
						swap(g[i][k],g[j][k]);
					}
					break;
				}
			}
		}
		if(fabs(g[i][i])<eps)continue;
		for(int j=i+1;j<=min(i+band,n);++j){
			double div=g[j][i]/g[i][i];
			for(int k=i;k<=min(i+2*band,n);++k){
				g[j][k]-=div*g[i][k];
			}
			g[j][n+1]-=div*g[i][n+1];
		}
	}
	for(int i=n;i>=1;--i){
		ans[i]=g[i][n+1];
		for(int j=i+1;j<=min(i+2*band,n);++j){
			ans[i]-=g[i][j]*ans[j];
		}
		ans[i]/=g[i][i];
	}
}
int main(){
	n=read(),m=read();
	int x=read(),y=read();
	if(m==1){
		printf("%.10lf\n",2.0*(n-x));
		return 0;
	}
	for(int i=n-1;i>=1;--i){
		g[1][1]=g[m][m]=2;
		g[1][2]=g[m][m-1]=-1;
		g[1][m+1]=3+ans[i+1][1];
		g[m][m+1]=3+ans[i+1][m];
		for(int j=2;j<m;++j){
			g[j][j]=3;
			g[j][j-1]=g[j][j+1]=-1;
			g[j][m+1]=4+ans[i+1][j];
		}
		Guass(m,1,ans[i]);
	}
	printf("%.10lf\n",ans[x][y]);
	return 0;
}