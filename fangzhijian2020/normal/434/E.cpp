#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,Y,K,X,i,j,k,val[100005],u,v,h[100005],vis[100005],cnt,mi[100005],inv[100005],minn,core,in[100005],out[100005],tot,d[100005];
long long ans;
struct node{
	int to,next;
}a[200005];
struct tt{
	int x,num;
}fg[100005],fh[100005];
bool cmp(const tt &a,const tt &b){
	return a.x<b.x;
}
void add(int x,int y){
	++cnt;a[cnt].to=y;a[cnt].next=h[x];h[x]=cnt;
}
int KSM(int x,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*x%Y;
		x=1ll*x*x%Y;n=n>>1;
	}
	return ans;
}
void DFS(int x,int prt,int G,int H,int deep){
	int i,y;
	tot++;fg[tot].num=fh[tot].num=x;
	fg[tot].x=(1ll*(X-G)%Y+Y)%Y*inv[deep+1]%Y;
	fh[tot].x=H;
	for(i=h[x];i;i=a[i].next){
		y=a[i].to;
		if(y!=prt&&!vis[y]){
			DFS(y,x,(1ll*G*K+val[y])%Y,(H+1ll*val[y]*mi[deep])%Y,deep+1);
		}
	}
}
void dfs(int x,int prt,int sum){
	int i,y,maxx=0;d[x]=1;
	for(i=h[x];i;i=a[i].next){
		y=a[i].to;
		if(y!=prt&&!vis[y]){
			dfs(y,x,sum);d[x]+=d[y];
			maxx=max(maxx,d[y]);
		}
	}
	maxx=max(maxx,sum-d[x]);
	if(maxx<=minn){
		minn=maxx;core=x;
	}
}
void cal(int opt){
	sort(fg+1,fg+tot+1,cmp);
	sort(fh+1,fh+tot+1,cmp);
	int now1,now2;
	for(i=1,j=1;i<=tot;i=now1){
		now1=i;
		while(fg[i].x==fg[now1].x&&now1<=tot)++now1;
		while(fh[j].x<fg[i].x&&j<=tot)++j;
		now2=j;while(fg[i].x==fh[now2].x&&now2<=tot)++now2;
		for(int k=i;k<now1;++k){
			in[fg[k].num]+=opt*(now2-j);
		}
		for(int k=j;k<now2;++k){
			out[fh[k].num]+=opt*(now1-i);
		}
		j=now2;
	}	
}
void DFZ(int x){
	int i,j,l,r,y;
	for(int i=h[x];i;i=a[i].next){
		y=a[i].to;if(vis[y])continue;tot=0;
		DFS(y,x,(1ll*val[x]*K+val[y])%Y,1ll*val[y]*mi[0]%Y,1);cal(-1);
	}
	tot=0;DFS(x,0,val[x],0,0);cal(1);vis[x]=1;
	for(i=h[x];i;i=a[i].next){
		y=a[i].to;
		if(!vis[y]){
			minn=n;
			dfs(y,0,d[y]);
			DFZ(core);
		}
	}
}
int main(){
	n=read();Y=read();K=read();X=read();
	for(i=1;i<=n;i++){
		val[i]=read();
	}
	for(i=1;i<n;i++){
		u=read();v=read();
		add(u,v);add(v,u);
	}
	mi[0]=1;in[0]=1;
	for(i=1;i<=n;i++){
		mi[i]=(1ll*mi[i-1]*K)%Y;
		inv[i]=KSM(mi[i],Y-2);
	}
	minn=n;
	dfs(1,0,n);DFZ(core);
	for(i=1;i<=n;i++){
		ans=ans+1ll*in[i]*(n-in[i])*2+1ll*out[i]*(n-out[i])*2+1ll*in[i]*(n-out[i])+1ll*(n-in[i])*out[i];
	}
	ans=ans>>1;ans=1ll*n*n*n-ans;
	cout<<ans<<"\n";
	return 0;
}