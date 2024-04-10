#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y;
};
vector<Node> tr[400005];
vector<int> ans;
int n,m,k; 
struct UFS{
	int fa[200005],size[200005],top;
	Node st[200005];
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
	if(x<=l&&r<=y)return tr[p].push_back({rx,ry});
	int mid=(l+r)/2;
	if(x<=mid)Modify(p*2,l,mid,x,y,rx,ry);
	if(mid<y)Modify(p*2+1,mid+1,r,x,y,rx,ry);
}
void GetAns(int p,int l,int r){
	int tp=f.top;
	for(Node now:tr[p]){
		int fx=f.gf(now.x),fy=f.gf(now.y);
		if(fx==fy)return f.Undo(tp);
		f.Merge(now.x,now.y+n),f.Merge(now.x+n,now.y);
	}
	if(l==r)return ans.push_back(l),f.Undo(tp);
	int mid=(l+r)/2;
	GetAns(p*2,l,mid),GetAns(p*2+1,mid+1,r),f.Undo(tp);
}
int main(){
	scanf("%d%d",&n,&m);
	if(!m)return puts("0"),0;
	f.Init(n*2);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(i>1)Modify(1,1,m,1,i-1,x,y);
		if(i<m)Modify(1,1,m,i+1,m,x,y);
	}
	GetAns(1,1,m);
	printf("%u\n",ans.size());
	for(int i:ans)printf("%d ",i);
    return 0;
}