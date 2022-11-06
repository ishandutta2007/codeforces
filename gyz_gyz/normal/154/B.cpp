#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 200000
using namespace std;
int n,m,x,y,u,v[N],p[N];char c[10];
int main(){
	scanf("%d%d",&n,&m);
	rep(t,1,m){
		scanf("%s",c);scanf("%d",&x);
		if(c[0]=='+'){y=x;u=0;
			if(p[x]){printf("Already on\n");continue;}
			rep(i,2,x){
				if(i*i>x)break;
				if(x%i==0){
					if(v[i]){
						printf("Conflict with %d\n",v[i]);
						u=1;break;
					}
					while(x%i==0)x/=i;
				}
			}
			if(x>1&&v[x]){
				printf("Conflict with %d\n",v[x]);u=1;
			}
			if(u)continue;
			x=y;printf("Success\n");p[x]=1;
			rep(i,2,x){
				if(i*i>x)break;
				if(x%i==0){v[i]=y;
					while(x%i==0)x/=i;
				}
			}
			if(x>1)v[x]=y;
		}else{
			if(!p[x]){printf("Already off\n");continue;}
			printf("Success\n");p[x]=0;
			rep(i,2,x){
				if(i*i>x)break;
				if(x%i==0){v[i]=0;
					while(x%i==0)x/=i;
				}
			}
			if(x>1)v[x]=0;
		}
	}
}