#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=5e5+100,maxn=5e5;
struct edge{
	int x,y,next;
}a[2*N];int len,last[N];
void ins(int x,int y){
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int fa[N],co[N],c[N],g[N],si[N],h[N];bool bz[N];
bool cmp(edge n1,edge n2){
	if(co[n1.x]==co[n2.x]) return (co[n1.y]<co[n2.y]);
	return (co[n1.x]<co[n2.x]);
}
int find(int x){
	if(fa[x]==x) return x;
	else{
		int t=find(fa[x]);
		c[x]=(c[x]+c[fa[x]])%2;
		fa[x]=t;return t;
	}
}
int Find(int x){
	if(fa[x]==x) return x;
	else return Find(fa[x]);
}
int main()
{
	int n,m,K;
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++) scanf("%d",&co[i]);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(co[x]<co[y]) ins(x,y);
		else ins(y,x);
	}
	memset(bz,true,sizeof(bz));
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i,c[i]=0,si[i]=1;
	for(int i=1;i<=len;i++)
		if(co[a[i].x]==co[a[i].y]&&bz[co[a[i].x]]){
			int x=find(a[i].x),y=find(a[i].y);
			if(x!=y){
				si[x]+=si[y];
				fa[y]=x;c[y]=(c[a[i].y]==c[a[i].x]);
			}
			else{
				if(c[a[i].y]==c[a[i].x])
					bz[co[a[i].x]]=false;
			}
		}
	for(int i=1;i<=n;i++) h[i]=si[i];
	for(int i=1;i<=n;i++) find(i);
	bool pd=true;ll Sum=0;
	for(int i=1;i<=len;i++){
		if(co[a[i].x]!=co[a[i-1].x]||co[a[i].y]!=co[a[i-1].y]){
			for(int j=1;j<=g[0];j++)
				fa[g[j]]=g[j],c[g[j]]=0,si[g[j]]=h[g[j]];
			g[0]=0;pd=true;
		}
		if(co[a[i].x]!=co[a[i].y]&&bz[co[a[i].x]]&&bz[co[a[i].y]]){
			int x=Find(a[i].x),y=Find(a[i].y);
			if(x!=y){
				int Sum1=0,Sum2=0,t1=a[i].x,t2=a[i].y;
				while(1){
					Sum1=(Sum1+c[t1])%2;
					if(t1==x) break;
					t1=fa[t1];
				}
				while(1){
					Sum2=(Sum2+c[t2])%2;
					if(t2==y) break;
					t2=fa[t2];
				}
				if(si[x]<si[y]) swap(x,y);
				g[++g[0]]=y;si[x]+=si[y];
				fa[y]=x;c[y]=(Sum1==Sum2);
			}
			else{
				int Sum1=0,Sum2=0,t1=a[i].x,t2=a[i].y;
				while(1){
					Sum1=(Sum1+c[t1])%2;
					if(t1==x) break;
					t1=fa[t1];
				}
				while(1){
					Sum2=(Sum2+c[t2])%2;
					if(t2==y) break;
					t2=fa[t2];
				}
				if(Sum1==Sum2){
					if(pd) Sum++,pd=false;
				}
			}
		}
	}
	int Sum2=0;
	for(int i=1;i<=K;i++)
		if(!bz[i]) Sum+=(K-1),Sum2++;
	Sum=Sum-(ll)Sum2*(Sum2-1)/2;
	Sum=(ll)(K-1)*K/2-Sum;
	printf("%lld\n",Sum);
	return 0;
}