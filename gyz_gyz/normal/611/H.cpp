#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define inf 1000000000
#define N 1000000
#define M 50
#define R(x) (m-k-1+(x))
using namespace std;
int n,m,k,u[N],v[N],a[M][M],ki[M][M],p[M][M];
int kk[M],f[M],nw[M],d[M],V[M],ls[M],fr[M];char st[M];
void flow(){
	for(;;){
		rep(i,1,m)d[i]=0,V[i]=0,fr[i]=0;d[1]=inf;
		for(;;){int x=m,y=0;
			rep(i,1,m-1)if(!V[i]&&d[i]>y)x=i,y=d[i];
			if(x==m)break;V[x]=1;
			rep(i,1,m)if(!V[i]){int z=a[x][i];if(y<z)z=y;
				if(z>d[i])d[i]=z,fr[i]=x;
			}
		}
		if(!d[m])break;
		for(int i=m;fr[i];i=fr[i])a[fr[i]][i]-=d[m],a[i][fr[i]]+=d[m];
	}
}
void pd(){
	rep(i,2,k){int j=i;rep(o,1,k){j=f[j];if(!j)break;if(i==j)return;}}
	rep(i,2,k)p[i][f[i]]--,p[f[i]][i]--;
	rep(i,1,m)rep(j,1,m)a[i][j]=0;
	rep(i,1,k)rep(j,i,k)a[1][ki[i][j]]=p[i][j];
	rep(i,1,k)a[m-k-1+i][m]=ls[i]-1;
	rep(i,1,k)rep(j,i,k){
		a[ki[i][j]][R(i)]=inf;
		a[ki[i][j]][R(j)]=inf;
	}
	flow();rep(i,2,k)p[i][f[i]]++,p[f[i]][i]++;
	rep(i,1,k)if(a[R(i)][m])return;
	rep(i,1,k)nw[i]=kk[i];
	rep(i,1,n-1){
		int x=u[i],y=v[i];
		if(f[x]==y||f[y]==x){
			if(f[x]==y)f[x]=0;if(f[y]==x)f[y]=0;
			printf("%d %d\n",kk[x],kk[y]);continue;
		}
		if(a[R(y)][ki[x][y]]){
			a[R(y)][ki[x][y]]--;
			printf("%d %d\n",kk[x],++nw[y]);
		}else{
			a[R(x)][ki[x][y]]--;
			printf("%d %d\n",++nw[x],kk[y]);
		}
	}
	exit(0);
}
void F(int x){
	if(x>k){pd();return;}
	rep(i,1,k)if(i!=x&&p[x][i]){f[x]=i;F(x+1);}
}
int main(){
	scanf("%d",&n);kk[1]=1;k=1;
	rep(i,2,8){
		kk[i]=kk[i-1]*10;if(kk[i]>n)break;k++;
	}
	rep(i,1,k-1)ls[i]=kk[i+1]-kk[i];ls[k]=n-kk[k]+1;
	rep(i,1,n-1){
		scanf("%s",st);u[i]=strlen(st);
		scanf("%s",st);v[i]=strlen(st);
	}
	rep(i,1,n-1)p[u[i]][v[i]]++,p[v[i]][u[i]]++;
	rep(i,1,k)p[i][i]/=2;
	m=1;rep(i,1,k)rep(j,i,k)ki[i][j]=ki[j][i]=++m;m+=k+1;F(2);
	printf("-1\n");
}