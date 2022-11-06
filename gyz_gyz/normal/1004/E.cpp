#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define abs(x) ((x)<0?-(x):(x))
#define N 1048576
#define ll long long
#define inf 1000000000
using namespace std;
int n,m,k,x,y,z,s,t,u,ans,tot;
int st[N],ed[N],nt[N],p[N],d[N],a[N],b[N],c[N],a1[N],a2[N],v[N],V[N],xt[N];
void lk(int x,int y,int z){
	if(!st[x])st[x]=++tot;else nt[ed[x]]=++tot;
	ed[x]=tot;p[tot]=y;d[tot]=z;
}
int dfs(int x){int dd=0;xt[x]=0;
	for(int i=st[x];i;i=nt[i])if(!v[p[i]]){
		v[p[i]]=1;int u=dfs(p[i])+d[i];
		if(u>dd)dd=u,xt[x]=p[i];v[p[i]]=0;
	}
	return dd;
}
bool mk(int x){int u=0;
	if(x==s){a[1]=x;V[x]=1;m=1;return 1;}
	for(int i=st[x];i;i=nt[i])if(!v[p[i]]){v[p[i]]=1;
		if(mk(p[i]))c[m]=d[i],a[++m]=x,V[x]=1,u=1;v[p[i]]=0;
	}
	return u;
}
int sl(int x){int dd=0;
	for(int i=st[x];i;i=nt[i])if((!v[p[i]])&&(!V[p[i]])){
		v[p[i]]=1;int u=sl(p[i])+d[i];
		if(u>dd)dd=u;v[p[i]]=0;
	}
	return dd;
}
int main(){
	scanf("%d%d",&n,&k);ans=inf;
	rep(i,1,n-1){
		scanf("%d%d%d",&x,&y,&z);
		lk(x,y,z);lk(y,x,z);
	}
	v[1]=1;dfs(1);v[1]=0;
	s=1;while(xt[s])s=xt[s];
	v[s]=1;dfs(s);v[s]=0;
	t=s;while(xt[t])t=xt[t];
	mk(t);rep(i,1,m)b[i]=sl(a[i]);
	a1[1]=b[1];a2[m]=b[m];
	rep(i,1,m-1)
		if(a1[i]+c[i]>b[i+1])a1[i+1]=a1[i]+c[i];
		else a1[i+1]=b[i+1];
	dep(i,m-1,1)
		if(a2[i+1]+c[i]>b[i])a2[i]=a2[i+1]+c[i];
		else a2[i]=b[i];
	if(k>m)k=m;
	rep(i,1,m-k+1){u=a1[i];
		if(a2[i+k-1]>u)u=a2[i+k-1];
		if(u<ans)ans=u;
	}
	rep(i,1,m)if(b[i]>ans)ans=b[i];
	printf("%d\n",ans);
}