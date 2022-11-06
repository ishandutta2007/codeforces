#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 2000001
using namespace std;
int a[mx],f[mx],nt[mx],h[mx],n,q,k,j,ans;long long p;
void gf(int x){if(f[x]!=x){gf(f[x]);h[x]+=h[f[x]];f[x]=f[f[x]];}}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)a[i+n]=a[i];
	rep(i,1,q){
		scanf("%d",&k);p=0;j=1;ans=n;
		rep(i,1,n*2){p+=a[i];
			while(p>k)nt[j]=i,p-=a[j++];
		}
		rep(i,1,n*2)if(!nt[i])nt[i]=n*2;
		rep(i,1,n*2)f[i]=i,h[i]=0;	
		rep(i,1,n)f[i]=nt[i],h[i]=1;
		rep(i,1,n){
			gf(i);if(h[i]<ans)ans=h[i];f[i+n]=nt[i+n];h[i+n]=1;
		}
		printf("%d\n",ans);
	}
}