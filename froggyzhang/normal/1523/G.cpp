#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int inf=0x3f3f3f3f;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
struct Range{
	int l,r;
}a[N];
int n,m;
vector<int> vec[N];
int root[N],ans[N];
struct Segment_Tree{
	int cnt;
	struct node{
		int ch[2],mn;
		node(){mn=inf;}
	}tree[N*200];
	#define ls tree[u].ch[0]
	#define rs tree[u].ch[1]
	void Insert(int &u,int L,int R,int x,int id){
		if(!u)u=++cnt;
		tree[u].mn=min(tree[u].mn,id);
		if(L==R)return;
		int mid=(L+R)>>1;
		if(x<=mid)Insert(ls,L,mid,x,id);
		else Insert(rs,mid+1,R,x,id);
	}
	int Query(int u,int L,int R,int l,int r){
		if(!u)return inf;
		if(L>=l&&R<=r)return tree[u].mn;
		int mid=(L+R)>>1;
		int mn=inf;
		if(l<=mid)mn=min(mn,Query(ls,L,mid,l,r));
		if(r>mid)mn=min(mn,Query(rs,mid+1,R,l,r));
		return mn;
	}
}T;
struct BIT{
	inline int lowbit(int x){return x&(-x);}
	void Insert(int x,int y,int id){
		while(y<=n){
			T.Insert(root[y],1,n,x,id);
			y+=lowbit(y);
		}
	}
	int Ask(int x,int y){	
		int mn=inf;
		while(y){
			mn=min(mn,T.Query(root[y],1,n,x,n));
			y-=lowbit(y);
		}
		return mn;
	}
}B;
int calc(){
	queue<pair<int,int> > q;
	q.push(make_pair(1,n));
	int ans=0;
	while(!q.empty()){
		int l=q.front().first,r=q.front().second;
		q.pop();
		if(l>r)continue;
		int u=B.Ask(l,r);
		if(u==inf)continue;
		ans+=a[u].r-a[u].l+1;
		q.push(make_pair(l,a[u].l-1));
		q.push(make_pair(a[u].r+1,r));
	}
	return ans;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		a[i].l=read(),a[i].r=read();
		vec[a[i].r-a[i].l+1].push_back(i);
	}
	for(int i=n;i>=1;--i){
		for(auto u:vec[i]){
			B.Insert(a[u].l,a[u].r,u);	
		}
		ans[i]=calc();
	}
	for(int i=1;i<=n;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}