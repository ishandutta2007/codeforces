#include<bits/stdc++.h>
using namespace std;
struct Query{
	int opt,x,y;
}q[500005];
struct Node{
	int x,y;
};
vector<Node> tr[2000005];
unordered_map<long long,int> mp;
int n,k,x[100005],y[100005],und[100005];
struct UFS{
	int fa[500005],size[500005],top;
	Node st[500005];
	void Init(int n){
		for(int i=1;i<=n;i++)fa[i]=i,size[i]=1;
	}
	int gf(int x){
		return x==fa[x]?x:gf(fa[x]);
	}
	void Merge(int x,int y){
		int fx=gf(x),fy=gf(y);
		if(fx==fy)return ;
		if(size[fx]>size[fy])swap(fx,fy);
		st[++top]={fx,fy};
		fa[fx]=fy,size[fy]+=size[fx];
	}
	void Undo(int k){
		while(top>k){
			int x=st[top].x,y=st[top].y;
			top--;
			fa[x]=x,size[y]-=size[x];
		}
	}
}f;
void Modify(int p,int l,int r,int x,int y,int rx,int ry){
	if(x<=l&&r<=y){
		tr[p].push_back({rx,ry});
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Modify(p*2,l,mid,x,y,rx,ry);
	if(mid<y)Modify(p*2+1,mid+1,r,x,y,rx,ry);
}
void GetAns(int p,int l,int r){
	int tp=f.top,flag=0;
	for(Node now:tr[p]){
		int fx=f.gf(now.x),fy=f.gf(now.y);
		if(fx==fy){
			for(int i=l;i<=r;i++)puts("NO");
			flag=1;
			break;
		}
		f.Merge(now.x,now.y+n),f.Merge(now.x+n,now.y);
	}
	if(flag)return f.Undo(tp),void();
	if(l==r){
		puts("YES");
		return f.Undo(tp),void();
	}
	int mid=(l+r)/2;
	GetAns(p*2,l,mid);
	GetAns(p*2+1,mid+1,r);
	f.Undo(tp);
}
int main(){
	scanf("%d%d",&n,&k);
	f.Init(n*2);
	for(int i=1,w;i<=k;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(w=mp[1ll*x[i]*100001+y[i]])und[w]=0,Modify(1,1,k,w,i-1,x[i],y[i]),mp[1ll*x[i]*100001+y[i]]=0;
		else mp[1ll*x[i]*100001+y[i]]=i,und[i]=1;
	}
	for(int i=1;i<=k;i++)if(und[i])Modify(1,1,k,i,k,x[i],y[i]);
	GetAns(1,1,k);
    return 0;
}