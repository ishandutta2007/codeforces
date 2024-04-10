#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
int n,m,dp[N],c[N],cnt;
pii a[N],b[N];
ll ans;
class BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	inline void Add(int x,int d){
		while(x)b[x]+=d,x-=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x<=n)ans+=b[x],x+=lowbit(x);
		return ans;
	}
}B;
class Segment_Tree{
	struct node{
		int mx,add;
		inline void Add(int d){
			add+=d,mx+=d;
		}	
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void pushdown(int u){
		if(t[u].add){
			t[ls].Add(t[u].add);
			t[rs].Add(t[u].add);
			t[u].add=0;
		}
	}
	inline void update(int u){
		t[u].mx=max(t[ls].mx,t[rs].mx);
	}
public:
	void build(int u,int L,int R){
		t[u].mx=t[u].add=0;
		if(L==R){
			t[u].mx=n-L;
			return;
		}
		int MID=(L+R)>>1;
		build(ls,L,MID);
		build(rs,MID+1,R);
		update(u);
	}
	void Plus(int u,int L,int R,int l,int r,int d){
		if(l>r)return;
		if(L>=l&&R<=r){
			t[u].Add(d);
			return;
		}
		pushdown(u);
		int MID=(L+R)>>1;
		if(l<=MID)Plus(ls,L,MID,l,r,d);
		if(r>MID)Plus(rs,MID+1,R,l,r,d);
		update(u);
	}
	void Change(int u,int L,int R,int p,int d){
		if(L==R){
			t[u].mx=d;
			return;
		}
		pushdown(u);
		int MID=(L+R)>>1;
		p<=MID?Change(ls,L,MID,p,d):Change(rs,MID+1,R,p,d);
		update(u);
	}
	int Query(int u,int L,int R,int l,int r){
		if(l>r)return -1;
		if(L>=l&&R<=r){
			return t[u].mx;
		}
		pushdown(u);
		int ans=-inf;
		int MID=(L+R)>>1;
		if(l<=MID)ans=max(ans,Query(ls,L,MID,l,r));
		if(r>MID)ans=max(ans,Query(rs,MID+1,R,l,r));
		return ans;
	}
	int get_ans(){
		return t[1].mx;
	}
}T;
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i].first>>a[i].second;	
	}
	sort(a+1,a+n+1,[&](pii i,pii j){return i.second<j.second;});
	int L=0;
	for(int i=1;i<=n;++i){
		if(a[i].second<=m)L=i;	
	}
	for(int i=1;i<=L;++i){
		dp[L]+=a[i].first>=m;
	}
	a[0].second=m;
    T.Change(1,0,n,L,dp[L]+n-L);
    for(int i=L+1;i<=n;++i){
    	b[++cnt]=make_pair(a[i].first,i);
    	B.Add(i,1);
    }
    for(int i=0;i<=n;++i){
    	c[i]=max(a[i].second,m);
    }
    sort(b+1,b+1+cnt);
    int p=1;
    for(int i=L+1;i<=n;++i){
        while(p<=cnt&&b[p].first<a[i].second){
            T.Plus(1,0,n,L,b[p].second-1,-1);
            B.Add(b[p].second,-1);
            ++p;
        }
        int MID=min((int)(upper_bound(c,c+1+n,a[i].first)-c),i);
        dp[i]=max(T.Query(1,0,n,L,MID-1)+1,T.Query(1,0,n,MID,i-1))-B.Ask(i);
        T.Change(1,0,n,i,dp[i]+B.Ask(i+1));
    }    
    cout<<dp[n]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}