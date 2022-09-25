#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
typedef pair<int,int> pii;
int n,m,Q;
template<int L>
class Basis{
	int d[L];
public:
	Basis(){memset(d,0,sizeof(d));}
	void Insert(int x){
		for(int i=29;i>=0;--i){
			if(x>>i&1){
				if(!d[i]){
					d[i]=x;return;
				}
				else{
					x^=d[i];
				}
			}
		}	
	}
	int Ask(int x){
		for(int i=29;i>=0;--i){
			if(x>>i&1)x^=d[i];	
		}
		return x;
	}
	void Merge(const Basis<L> &B){
		for(int i=29;i>=0;--i){
			if(B.d[i])Insert(B.d[i]);	
		}
	}
};
using bas=Basis<30>;
class Union_Set{
	int f[N],siz[N],dis[N],fw[N];
	bas b[N];
	inline pii getf(int x){
		if(f[x]==x)return pii(x,0);
		pii tmp=getf(f[x]);
		tmp.second^=fw[x];
		return tmp;	
	}
public:
	vector<pair<pii,bas> > bin;
	void init(int n){
		for(int i=1;i<=n;++i){
			siz[i]=1,f[i]=i;
		}
	}
	void Merge(int x,int y,int d){
		auto [fx,dx]=getf(x);
		auto [fy,dy]=getf(y);
		if(fx==fy){
			bin.emplace_back(pii(fx,fx),b[fx]);
			b[fx].Insert(dx^dy^d);
			return;
		}
		if(siz[fx]<siz[fy]){
			swap(fx,fy),swap(dx,dy);
		}
		fw[fy]=dx^dy^d;
		f[fy]=fx;
		bin.emplace_back(pii(fx,fy),b[fx]);
		b[fx].Merge(b[fy]);
		siz[fx]+=siz[fy];
	}
	int Query(int x,int y){
		auto [fx,dx]=getf(x);
		auto [fy,dy]=getf(y);
		return b[fx].Ask(dx^dy);
	}
	void Revoke(){
		auto [t,B]=bin.back();
		bin.pop_back();
		auto [x,y]=t;
		if(x^y){
			fw[y]=0,f[y]=y;
			siz[x]-=siz[y];
		}
		b[x]=B;
	}
}S;
struct Data{
	int x,y,d;	
	Data(int _x=0,int _y=0,int _d=0):x(_x),y(_y),d(_d){};
};
#define ls u<<1
#define rs u<<1|1
vector<Data> c[N<<2];
map<pii,pii> mp;
pii q[N];
void Cover(int u,int L,int R,int l,int r,Data t){
	if(l>r)return;
	if(L>=l&&R<=r){
		c[u].push_back(t);
		return;
	}
	int mid=(L+R)>>1;
	if(l<=mid)Cover(ls,L,mid,l,r,t);
	if(r>mid)Cover(rs,mid+1,R,l,r,t);
}
void Solve(int u,int L,int R){
	int las=S.bin.size();
	for(auto [x,y,d]:c[u]){
		S.Merge(x,y,d);
	}
	if(L==R){
		if(q[L].first){
			auto [x,y]=q[L];
			cout<<S.Query(x,y)<<'\n';
		}
	}
	else{
		int mid=(L+R)>>1;
		Solve(ls,L,mid);
		Solve(rs,mid+1,R);
	}
	while(S.bin.size()>las){
		S.Revoke();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	S.init(n);
	for(int i=1;i<=m;++i){
		int x,y,d;	
		cin>>x>>y>>d;
		mp[pii(x,y)]=pii(d,1);
	}
	cin>>Q;
	for(int i=1;i<=Q;++i){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==1){
			int d;
			cin>>d;
			mp[pii(x,y)]=pii(d,i);	
		}
		else if(opt==2){
			Cover(1,1,Q,mp[pii(x,y)].second,i-1,Data(x,y,mp[pii(x,y)].first));
			mp.erase(pii(x,y));	
		}
		else{
			q[i]=pii(x,y);	
		}
	}
	for(auto t:mp){
		Cover(1,1,Q,t.second.second,Q,Data(t.first.first,t.first.second,t.second.first));	
	}
	Solve(1,1,Q);
	return 0;
}