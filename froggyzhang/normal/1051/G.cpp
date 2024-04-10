#include<bits/stdc++.h>
using namespace std;
#define N 400040
typedef long long ll;
int n,vis[N];
ll ans;
class Union_Set{
public:
	int f[N],L[N];
	ll s[N];
	void init(int n){for(int i=1;i<=n;++i)f[i]=i,L[i]=i;}
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
}S;
class Segment_tree{
	int cnt;
	struct node{
		int ch[2],siz;
		ll sum,all;
	}t[N<<4];
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
public:
	int rt[N];
	inline ll calc(int u){
		return t[rt[u]].all;
	}
	inline void update(int u){
		t[u].siz=t[ls].siz+t[rs].siz;
		t[u].sum=t[ls].sum+t[rs].sum;
		t[u].all=t[ls].all+t[rs].all+t[ls].sum*t[rs].siz;
	}	
	void Insert(int &u,int L,int R,int x){
		if(!u)u=++cnt;
		if(L==R){
			++t[u].siz,t[u].sum+=x;
			return;
		}
		int mid=(L+R)>>1;
		x<=mid?Insert(ls,L,mid,x):Insert(rs,mid+1,R,x);
		update(u);
	}
	void Merge(int &u,int v,int L,int R){
		if(!u||!v){u|=v;return;}
		if(L==R){
			t[u].sum+=t[v].sum;t[u].siz+=t[v].siz;
			return;
		}
		int mid=(L+R)>>1;
		Merge(ls,t[v].ch[0],L,mid);
		Merge(rs,t[v].ch[1],mid+1,R);
		update(u);
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	S.init(400000);
	ll jb=0;
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		jb+=1LL*x*y;
		if(vis[x-1])--x;
		if(vis[x]){
			x=S.getf(x);
			S.f[x]=x+1;S.L[x+1]=S.L[x],S.s[x+1]=S.s[x];++x;
			T.rt[x]=T.rt[x-1];
		}
		ans+=1LL*S.L[x]*y;
		S.s[x]+=y;
		ans-=T.calc(x);
		vis[x]=1;
		T.Insert(T.rt[x],1,n,y);
		ans+=T.calc(x);
		if(vis[x+1]){
			int z=S.getf(x+1);
			S.f[x]=z;
			ans+=S.s[z]*(S.L[x]-S.L[z]);
			S.L[z]=S.L[x];
			S.s[z]+=S.s[x];
			ans-=T.calc(z)+T.calc(x);
			T.Merge(T.rt[z],T.rt[x],1,n);
			ans+=T.calc(z);	
		}
		cout<<ans-jb<<'\n';
	}
	return 0;
}