#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,Q,mod,p[11],m,phi,a[N],pw[11][N*20];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
class Segment_Tree{
	struct node{
		array<int,10> add,cnt;
		int sum,num,tm;
		node(){num=tm=sum=1;}
		inline void Add(const array<int,10> &d,int w){
			for(int i=0;i<m;++i){
				if(d[i]){
					add[i]+=d[i],cnt[i]+=d[i];
					sum=1LL*sum*pw[i][d[i]]%mod;
				}
			}
			num=1LL*num*w%mod;
			sum=1LL*sum*w%mod;
			tm=1LL*tm*w%mod;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].sum=(t[ls].sum+t[rs].sum)%mod;	
	}
	inline void pushdown(int u){
		t[ls].Add(t[u].add,t[u].tm);
		t[rs].Add(t[u].add,t[u].tm);
		for(int i=0;i<m;++i)t[u].add[i]=0;
		t[u].tm=1;	
	}
public:
	int Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return t[u].sum;
		int tot=0;
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)tot+=Query(ls,L,mid,l,r);
		if(r>mid)tot=(tot+Query(rs,mid+1,R,l,r))%mod;
		return tot;	
	}
	void _Mul(int u,int L,int R,int l,int r,const array<int,10> &d,int w){
		if(L>=l&&R<=r){
			t[u].Add(d,w);
			return;
		}
		int mid=(L+R)>>1;
		pushdown(u);
		if(l<=mid)_Mul(ls,L,mid,l,r,d,w);
		if(r>mid)_Mul(rs,mid+1,R,l,r,d,w);
		update(u);
	}
	void Change(int u,int L,int R,int pos,const array<int,10> &d,int w){
		if(L==R){
			for(int i=0;i<m;++i){
				t[u].cnt[i]-=d[i];
			}
			t[u].sum=t[u].num=1LL*t[u].num*qpow(w,phi-1)%mod;
			for(int i=0;i<m;++i){
				t[u].sum=1LL*t[u].sum*qpow(p[i],t[u].cnt[i])%mod;
			}
			return;	
		}
		int mid=(L+R)>>1;
		pushdown(u);
		pos<=mid?Change(ls,L,mid,pos,d,w):Change(rs,mid+1,R,pos,d,w);
		update(u);
	}
}T;
void Split(int x){
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			while(x%i==0)x/=i;
			p[m++]=i;
		}	
	}
	if(x>1)p[m++]=x;
}
pair<array<int,10>,int> Get(int x){
	array<int,10> d={};
	for(int i=0;i<m;++i){
		while(x%p[i]==0)x/=p[i],++d[i];
	}	
	return make_pair(d,x);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>mod;
	Split(mod);
	phi=mod;
	for(int i=0;i<m;++i){
		phi=phi/p[i]*(p[i]-1);
	}
	for(int i=0;i<m;++i){
		pw[i][0]=1;
		for(int j=1;j<=2000000;++j){
			pw[i][j]=1LL*pw[i][j-1]*p[i]%mod;
		}
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		auto [d,w]=Get(a[i]);
		T._Mul(1,1,n,i,i,d,w);
	}
	cin>>Q;
	while(Q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int l,r,x;
			cin>>l>>r>>x;
			auto [d,w]=Get(x);
			T._Mul(1,1,n,l,r,d,w);
		}
		else if(opt==2){
			int p,x;
			cin>>p>>x;
			auto [d,w]=Get(x);
			T.Change(1,1,n,p,d,w);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<T.Query(1,1,n,l,r)<<'\n';
		}
	}
	return 0;
}