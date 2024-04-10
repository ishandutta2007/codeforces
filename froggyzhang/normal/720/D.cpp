#include<bits/stdc++.h>
using namespace std;
#define N 1000100
const int mod=1e9+7;
typedef long long ll;
int n,m,K;
class Segment_Tree{
	struct node{
		int sum,ze;
		void Ze(){
			ze=1,sum=0;
		}	
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].sum=(t[ls].sum+t[rs].sum)%mod;	
	}
	inline void pushdown(int u){
		if(t[u].ze){
			t[ls].Ze();
			t[rs].Ze();
			t[u].ze=0;
		}	
	}
public:
	int Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].sum;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		int ans=0;
		if(l<=mid)ans=Query(ls,L,mid,l,r);
		if(r>mid)ans=(ans+Query(rs,mid+1,R,l,r))%mod;
		return ans;
	}
	void Plus(int u,int L,int R,int pos,int d){
		if(L==R){
			t[u].sum=(t[u].sum+d)%mod;
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		pos<=mid?Plus(ls,L,mid,pos,d):Plus(rs,mid+1,R,pos,d);
		update(u);
	}
	void Zero(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			t[u].Ze();
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Zero(ls,L,mid,l,r);
		if(r>mid)Zero(rs,mid+1,R,l,r);
		update(u);
	}
	/*
	void dfs(int u,int L,int R){
		if(L==R){
			cout<<t[u].sum<<' ';
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		dfs(ls,L,mid);
		dfs(rs,mid+1,R);	
	} 
	*/
}T;
struct Block{
	int l,r,w;
	friend bool operator < (const Block &a,const Block &b){
		return a.w^b.w?a.w>b.w:a.l>b.l;	
	}
};
vector<Block> q[N];
multiset<pair<int,int> > S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=K;++i){
		int X1,Y1,X2,Y2;
		cin>>X1>>Y1>>X2>>Y2;
		q[X1].push_back({Y1,Y2,1});
		q[X2+1].push_back({Y1,Y2,-1});	
	}
	T.Plus(1,1,m,1,1);
	for(int i=1;i<=n;++i){
		sort(q[i].begin(),q[i].end());
	}
	S.emplace(0,0);
	for(int i=1;i<=n;++i){
		for(auto t:q[i]){
			int l=t.l,r=t.r,w=t.w;
			if(w==1){
				if(i>1){
					pair<int,int> p=*--S.lower_bound(make_pair(r+2,-1));
					if(r<m&&p.second<r){
						int jb=T.Query(1,1,m,p.second+1,r);
						T.Plus(1,1,m,r+1,jb);	
					}
				}
				T.Zero(1,1,m,l,r);
				S.emplace(l,r);
			}
			else{
				S.erase(S.find(make_pair(l,r)));	
			}
		}
		//T.dfs(1,1,m);
	}
	int pos=S.rbegin()->second;
	cout<<T.Query(1,1,m,pos+1,m)<<'\n';
	return 0;
}