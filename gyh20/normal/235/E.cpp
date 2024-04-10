#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define ll long long
#define M 1073741824
#define re register
using namespace std;
int n,m,T,ip[100002],num,mu[100002],A,B,C,mx,head[100002],tot,vis[100002],cnt;
vector<int>v[100002];
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct Edge{int x,y,l;}E[3500002];
ll du[100002],s1[100002],s2[100002],s3[100002];
struct edge{int next,to,l;}e[3500002];
inline void add(int x,int y,int z){
    e[++tot]=(edge){head[x],y,z};
    head[x]=tot;
}
inline int check(int a,int b,int c,int x,int y,int Z){
    return mu[a]*mu[b]*mu[c]*(s1[x]*s2[y]%M*s3[Z])%M;
}
int main(){
	mu[1]=1;
	for(re int i=2;i<=100000;++i)
		if(!ip[i]){
			mu[i]=1;
			for(re int j=1;j*i<=100000;++j){
				ip[i*j]=1,v[j*i].push_back(i);
				if(j%i)mu[i*j]=-mu[j];}
			}A=read();B=read();C=read();
		mx=max(max(A,B),C);
		for(re int i=1;i<=mx;++i){
			s1[i]=s2[i]=s3[i]=0;
			for(re int j=i;j<=mx;j+=i)(s1[i]+=A/j)%=M,(s2[i]+=B/j)%=M,(s3[i]+=C/j)%=M;
   	 	}
		for(re int i=1;i<=mx;++i){
			if(!mu[i])continue;
			re int tot=v[i].size();
			for(int j=0;j<(1<<tot);j++){
				int x=1,now=j;for(int k=0;k<tot;k++,now>>=1)if(now&1)x*=v[i][k];
				for(int k=j;;k=(k-1)&j){
					re int g=1,tmp=k;
					for(re int h=0;h<tot;++h,tmp>>=1)if(tmp&1)g*=v[i][h];
					re int y=(ll)i*g/x;
					if(x<y)E[++cnt]=(Edge){x,y,i},++du[x],++du[y];
					if(!k)break;
				}
			}
		}
		for(re int i=1;i<=cnt;++i){
			if(du[E[i].x]>=du[E[i].y])add(E[i].x,E[i].y,E[i].l);
			else add(E[i].y,E[i].x,E[i].l);
		}
		re ll ans=0;
		for(re int i=1;i<=mx;++i){
			for(re int j=head[i];j;j=e[j].next)vis[e[j].to]=e[j].l;
			for(re int j=head[i];j;j=e[j].next){
				re int u=e[j].to,l=e[j].l;
				for(re int k=head[u];k;k=e[k].next)
					if(vis[e[k].to]){
						re int A_B=l,A_C=vis[e[k].to],B_C=e[k].l;
						(ans+=((ll)check(i,u,e[k].to,A_B,A_C,B_C)+check(i,e[k].to,u,A_C,A_B,B_C)+check(u,i,e[k].to,A_B,B_C,A_C)+check(u,e[k].to,i,B_C,A_B,A_C)+check(e[k].to,i,u,A_C,B_C,A_B)+check(e[k].to,u,i,B_C,A_C,A_B))%M)%=M;
					}
			}
			for(re int j=head[i];j;j=e[j].next)vis[e[j].to]=0;
		}
		for(re int i=1;i<=mx;++i)if(mu[i])for(re int j=head[i];j;j=e[j].next)(ans+=((ll)check(i,i,e[j].to,i,e[j].l,e[j].l)+check(i,e[j].to,i,e[j].l,i,e[j].l)+check(e[j].to,i,i,e[j].l,e[j].l,i)+check(i,e[j].to,e[j].to,e[j].l,e[j].l,e[j].to)+check(e[j].to,e[j].to,i,e[j].to,e[j].l,e[j].l)+check(e[j].to,i,e[j].to,e[j].l,e[j].to,e[j].l))%M)%=M;
		for(re int i=1;i<=mx;++i)if(mu[i])(ans+=check(i,i,i,i,i,i))%=M;
		printf("%d\n",ans<0?ans+M:ans);
}