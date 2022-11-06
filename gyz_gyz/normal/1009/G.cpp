#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 200010
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,m,tot,x,t,fw,rt,ans;char str[N];
int s[N],st[N],ed[N],nt[N],p[N],w[N],v[N],pr[N],fl[N],q[N],ss[N];
void lk(int x,int y,int z){
	if(!st[x])st[x]=++tot;else nt[ed[x]]=++tot;
	ed[x]=tot;p[tot]=y;w[tot]=z;
	if(!st[y])st[y]=++tot;else nt[ed[y]]=++tot;
	ed[y]=tot;p[tot]=x;
}
void dfs(int x){v[x]=1;
	for(int i=st[x];i;i=nt[i])if(w[i]&&(!v[p[i]])){
		pr[p[i]]=i^1;dfs(p[i]);
	}
}
int main(){
	for(scanf("%s",str);str[n];n++)s[str[n]-'a']++;
	scanf("%d",&m);tot=1;
	rep(i,1,m){
		rep(j,0,5)v[j]=1;t=0;
		scanf("%d",&x);scanf("%s",str);
		for(int j=0;str[j];j++)v[str[j]-'a']=0;
		rep(j,0,5)if(v[j])t+=1<<j;q[x]=t;
	}
	rep(i,0,5)v[i]=0;
	rep(i,1,n)ss[q[i]]++;
	rep(i,0,5)lk(1,2+i,s[i]);
	rep(i,0,62)lk(8+i,71,ss[i]);
	rep(i,0,5)rep(j,0,62)if(!((j>>i)&1))lk(2+i,8+j,inf);
	for(;;){
		rep(i,1,71)v[i]=fl[i]=0;fl[1]=inf;
		rep(o,1,71){fw=0;
			rep(i,1,71)if((!v[i])&&(fl[i]>fw))fw=fl[i],rt=i;
			if(!fw)break;v[rt]=1;
			for(int i=st[rt];i;i=nt[i])
				if(min(w[i],fw)>fl[p[i]]){
					fl[p[i]]=min(w[i],fw);pr[p[i]]=i^1;
				}
		}
		if(!fl[71])break;ans+=fl[71];
		for(int i=pr[71];i;i=pr[p[i]])w[i]+=fl[71],w[i^1]-=fl[71];
	}
	if(ans<n){printf("Impossible");return 0;}
	rep(i,1,n){
		rep(j,1,71)v[j]=0;pr[8+q[i]]=0;dfs(8+q[i]);
		rep(j,0,5)if(v[2+j]&&(!((q[i]>>j)&1))){
			printf("%c",'a'+j);
			for(int k=pr[2+j];k;k=pr[p[k]])w[k]++,w[k^1]--;break;
		}
	}
}