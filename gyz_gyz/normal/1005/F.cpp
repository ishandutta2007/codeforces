#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1048576
#define inf 1000000000
using namespace std;
int n,m,k,x,y,s,t,ans,tot,ss,u;
int dl[N],st[N],ed[N],nt[N],p[N],v[N],us[N],h[N];
void lk(int x,int y){
	if(!st[x])st[x]=++tot;else nt[ed[x]]=++tot;
	ed[x]=tot;p[tot]=y;
}
void f(int x){
	if(x>n){
		rep(i,1,m)printf("%d",us[i]);
		printf("\n");ans--;
		if(!ans)exit(0);
	}
	for(int i=st[x];i;i=nt[i])if(h[p[i]]==h[x]-1){
		us[(i+1)/2]=1;f(x+1);us[(i+1)/2]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		lk(x,y);lk(y,x);
	}
	dl[1]=1;s=1;t=1;v[1]=1;
	while(s<=t){ss=dl[s];
		for(int i=st[ss];i;i=nt[i])if(!v[p[i]]){
			dl[++t]=p[i];
			h[p[i]]=h[ss]+1;
			v[p[i]]=1;
		}
		s++;
	}
	rep(i,1,n)v[i]=0;ans=1;
	rep(i,2,n){u=0;
		for(int j=st[i];j;j=nt[j])if(h[p[j]]==h[i]-1)u++;
		ans*=u;if(ans>k){ans=k;break;}
	}
	printf("%d\n",ans);
	f(2);
}