#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 20001
using namespace std;
int a[mx],p[mx],w[mx],n,m,t,t1,t2,t3,s,x,u,tot;
int main(){
	scanf("%d%d%d",&n,&m,&t);s=1;
	rep(i,1,n){
		scanf("%d:%d:%d",&t1,&t2,&t3);
		a[i]=t1*3600+t2*60+t3;
	}
	rep(i,1,n){
		for(;a[i]-a[s]>=t;s++){
			w[p[s]]--;if(!w[p[s]])tot--;
		}
		if(tot<m)p[i]=++x,w[x]++,tot++;
		else p[i]=p[i-1],w[p[i]]++;
		if(tot==m)u=1;
	}
	if(!u)return printf("No solution"),0;
	printf("%d\n",x);
	rep(i,1,n)printf("%d\n",p[i]);
}