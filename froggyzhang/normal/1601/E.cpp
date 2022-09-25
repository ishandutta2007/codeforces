#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
typedef pair<int,int> pii;
int n,m,K,a[N],f[N][20],lg[N],val[N];
vector<pii> q[N];
ll ans[N];
class Segment_Tree{
	struct node{
		int cov,len;
		ll sum;
		inline void Cov(int d){
			cov=d,sum=1LL*d*len;
		}	
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void pushdown(int u){
		if(~t[u].cov){
			t[ls].Cov(t[u].cov);
			t[rs].Cov(t[u].cov);
			t[u].cov=-1;
		}
	}
	inline void update(int u){
		t[u].sum=t[ls].sum+t[rs].sum;
	}
public:
	void build(int u,int L,int R){
		t[u].len=R-L+1;
		t[u].sum=0,t[u].cov=-1;
		if(L==R){
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
	}
	void Cover(int u,int L,int R,int l,int r,int d){
		if(l>r)return;
		if(L>=l&&R<=r){
			t[u].Cov(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Cover(ls,L,mid,l,r,d);
		if(r>mid)Cover(rs,mid+1,R,l,r,d);
		update(u);
	}
	ll Query(int u,int L,int R,int l,int r){
		if(l>r)return 0;
		if(L>=l&&R<=r){
			return t[u].sum;
		}
		pushdown(u);
		ll sum=0;
		int mid=(L+R)>>1;
		if(l<=mid)sum+=Query(ls,L,mid,l,r);
		if(r>mid)sum+=Query(rs,mid+1,R,l,r);
		return sum;
	}
}T;
inline int Query(int l,int r){
	int k=lg[r-l+1];
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		f[i][0]=a[i];
	}
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);	
		}	
	}
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	for(int i=K+1;i<=n;++i){
		val[i]=Query(i-K,i);
	}
	for(int i=1;i<=m;++i){
		int l,r;
		cin>>l>>r;
		q[l].emplace_back(r,i);
	}
	for(int i=1;i<=K;++i){
		static int pos[N],len;
		len=0;
		for(int j=i;j<=n;j+=K){
			pos[++len]=j;	
		}
		T.build(1,1,len);
		static int st[N],top;
		top=0;
		for(int j=len;j>=1;--j){
			int u=pos[j];
			for(auto [r,id]:q[u]){
				ans[id]=a[u]+T.Query(1,1,len,j+1,(r-i)/K+1);
			}
			while(top&&val[u]<=val[pos[st[top]]])--top;
			T.Cover(1,1,len,j,!top?len:st[top]-1,val[u]);
			st[++top]=j;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}