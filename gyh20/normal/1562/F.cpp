#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline ll read(){
	re ll t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,p[100002],ans[102],pri[200002],cnt;
char v[200002];
ll f[102][102],L1[102],L2[102];
inline ll lcm(re int x,re int y){return 1ll*x*y/__gcd(x,y);}
inline ll ask(re int x,re int y){
	printf("? %d %d\n",x,y),fflush(stdout);
	return read();
}
inline int Get(re ll x){
	re int s=0;
	for(re int i=1;i<=cnt&&1ll*pri[i]*pri[i]<=x;++i)while(x%pri[i]==0)x/=pri[i],s=pri[i];
	if(x>1)s=max(1ll*s,x);return s;
}
inline int Rand(re int x){
	return ((rand()<<15)|rand())%x+1;
}
int main(){
	t=read(),n=2e5;
	for(re int i=2;i<=n;++i)
		if(!v[i]){
			pri[++cnt]=i;
			for(re int j=i+i;j<=n;j+=i)v[j]=1;
		}
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)p[i]=i;
		if(n<=100){
			re ll mx=0;
			for(re int i=1;i<=n;++i)
				for(re int j=i+1;j<=n;++j)
					f[i][j]=f[j][i]=ask(i,j),mx=max(mx,f[i][j]);
			re int r=0;
			while(1ll*r*(r-1)<mx)++r;
			re int l=r-n+1,p1,p2;
			for(re int i=1;i<=n;++i)
				for(re int j=i+1;j<=n;++j)
					if(f[i][j]==mx)
						p1=i,p2=j;
			for(re int i=1;i<=n;++i){
				L1[i]=lcm(i+l-1,r),L2[i]=lcm(i+l-1,r-1);
				if(L1[i]>L2[i])swap(L1[i],L2[i]);
			}
			for(re int i=1;i<=n;++i)if(i^p1&&i^p2){
				re ll x1=f[i][p1],x2=f[i][p2];
				if(x1>x2)swap(x1,x2);
				for(re int j=1;j<=n;++j)if(x1==L1[j]&&x2==L2[j])ans[i]=j+l-1;
				if(f[i][p1]==lcm(ans[i],r))ans[p1]=r,ans[p2]=r-1;
				else ans[p1]=r-1,ans[p2]=r;
			}
		}
		else{
			re int p1=0,p2=0,mx=0;
			for(re int i=1;i<=4900;++i){
				re int x=Rand(n),y=Rand(n);
				while(x==y)y=Rand(n);
				int vv=Get(ask(x,y));
				if(vv>mx)mx=vv,p1=x,p2=y;
			}
			re int pos=1;
			while(pos==p1||pos==p2)++pos;
			if(ask(p1,pos)%mx)swap(p1,p2);
			ans[p1]=mx;
			for(re int i=1;i<=n;++i)if(i^p1)ans[i]=ask(i,p1)/mx;
		}
		printf("! ");
		for(re int i=1;i<=n;++i)printf("%d ",ans[i]);
		puts(""),fflush(stdout);
	}
}