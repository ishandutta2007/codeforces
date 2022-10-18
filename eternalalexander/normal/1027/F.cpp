#include <bits/stdc++.h>
#define maxn 1000005
int n,a[maxn],b[maxn],h[maxn*2],p[maxn],q[maxn],tl=0;

namespace dsu {
	int fa[maxn<<1]={0},vis[maxn<<1]={0};
	void reset(){std::memset(fa,0,sizeof(fa));std::memset(vis,0,sizeof(vis));}
	int getf(int x){return fa[x]?fa[x]=getf(fa[x]):x;}
	int Union(int x,int y){
	//	printf("link %d %d\n",x,y);
		int f1=getf(x),f2=getf(y);
		if (f1!=f2){
			fa[f2]=f1;
			if (vis[f1]&&vis[f2])return 0;
			vis[f1]|=vis[f2];
		}else {
			if (vis[f1])return 0;
			vis[f1]=1;
		}return 1;
	}
}

int check(int x){
//	printf("checking %d\n",x);
	dsu::reset();
	for(int i=1;i<=n;++i){
		if (x<a[i])return 0;
		else if (x<b[i]){
			if (!dsu::Union(p[i],p[i]))return 0;
		}
		else{ 
			if (!dsu::Union(p[i],q[i]))return 0;
		}
	}return 1;
}
			

int main(){
//	freopen("exam.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]>b[i])std::swap(a[i],b[i]);
		h[++tl]=a[i];h[++tl]=b[i];
	}std::sort(h+1,h+tl+1);tl=std::unique(h+1,h+tl+1)-(h+1);//printf("%d\n",tl);
	for(int i=1;i<=n;++i){
		p[i]=std::lower_bound(h+1,h+tl+1,a[i])-(h+1)+1;
		q[i]=std::lower_bound(h+1,h+tl+1,b[i])-(h+1)+1;
	}int l=1,r=tl,ans=-1;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(h[mid])){ans=mid;r=mid-1;}
		else l=mid+1;
	}printf("%d",ans!=-1?h[ans]:ans);
	return 0;
}