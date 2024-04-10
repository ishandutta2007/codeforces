#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


 
template<typename T, typename S>
struct LazySegmentTree{
private:
	int n;
	vector<T> node;
	vector<S> lazy;
	T E0;
	S E1;

	inline void updatef(S& lazy,S& value){
		//lazy += value;
		lazy = min(value,lazy);
		//lazy = max(lazy, value);
		//lazy = min(lazy, value);
	}
	inline void calculatef(T& node,S& lazy,int len){
		//node += lazy * len; //sum
		// node += lazy ; //max
		node = min(lazy,node) ;
	}
	inline T queryf(T& x,T& y){
		//return x + y;
		//return x * y;
		//return max(x, y);
		return min(x, y);
	}
public:
	LazySegmentTree(int sz,T nodeE,S lazyE ):E0(nodeE), E1(lazyE){
		n=1;
		while(n<sz)n<<=1;
		node.resize(2*n-1,E0);
		lazy.resize(2*n-1,E1);
	}

	LazySegmentTree(vector<T>& v,T E0,S E1 ):E0(E0),E1(E1){
		n=1;
		int sz=v.size();
		while(n<sz)n<<=1;
		node.resize(2*n-1,E0);
		lazy.resize(2*n-1,E1);
		rep(i,sz)node[i+n-1] = v[i];
		for(int i=n-2; i>=0; --i){
			node[i] = queryf(node[2*i+1],node[2*i+2]);
		}
	}

	void eval(int k,int l,int r){
		if(lazy[k]==E1)return ;
		calculatef(node[k], lazy[k], r-l);
		if(r-l>1){
			updatef(lazy[2*k+1], lazy[k]);
			updatef(lazy[2*k+2], lazy[k]);
		}
		lazy[k]=E1;
	}

	void update(int a, int b, S x,int k=0,int l=0,int r=-1){
		if(r<0)r=n;
		eval(k,l,r);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			updatef(lazy[k], x);
			eval(k,l,r);
		}
		else {
			update(a,b,x,2*k+1,l,(l+r)/2);
			update(a,b,x,2*k+2,(l+r)/2,r);
			node[k]=queryf(node[2*k+1], node[2*k+2]);
		}
	}

	T query(int a,int b,int k=0,int l=0,int r=-1){
		if(r<0)r=n;
		eval(k,l,r);
		if(r<=a||b<=l)return E0;
		if(a<=l&&r<=b)return node[k];
		T xl=query(a,b,2*k+1,l,(l+r)/2);
		T xr=query(a,b,2*k+2,(l+r)/2,r);
		return queryf(xl, xr);
	}
};
LazySegmentTree<int,int> sg(151515,1000000000,1000000000);
 
struct HLDecomposition{
    int n,pos;
    vector<vector<int>> v;
    vector<int> idx,head,sz,hvy,par,depth,inv,type;
 
    HLDecomposition(){};
    HLDecomposition(int s):
        n(s),pos(0),v(n),idx(n,-1),head(n),sz(n,1),
        hvy(n,-1),par(n),depth(n),inv(n),type(n){}
     
    void addedge(int x,int y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
 
    void dfs1(int rt){
        par[rt]=-1;
        depth[rt]=0;
        stack<pair<int,int>> st;
        st.push({rt,0});
        while(!st.empty()){
            int x=st.top().first;
            int& i=st.top().second;
            if(i<(int)v[x].size()){
                int to=v[x][i++];
                if(to==par[x])continue;
                par[to]=x;
                depth[to]=depth[x]+1;
                st.push({to,0});
            }
            else {
                st.pop();
                int res=0;
                for(int to:v[x]){
                    if(to==par[x])continue;
                    sz[x]+=sz[to];
                    if(sz[to]>res)res=sz[to],hvy[x]=to;
                }
            }
        }
    }
    void dfs2(int r,int c){
        int &k=pos;
        stack<int> st;
        st.push(r);
        while(!st.empty()){
            int h=st.top();st.pop();
            for(int x=h;x!=-1;x=hvy[x]){
                type[x]=c;
                head[x]=h;
                idx[x]=k++;
                inv[idx[x]]=x;
                for(int to:v[x])
                    if(to!=par[x]&&to!=hvy[x])st.push(to);
            }
        }
    }
 
    void build(vector<int> rs=vector<int>(1,0)){
        int c=0;
        for(int r:rs){
            dfs1(r);
            dfs2(r,c++);
        }
    }
    void for_edge(int x,int y,int z){
        while(1){
            if(idx[x]>idx[y])swap(x,y);
            if(head[x]!=head[y]){
                sg.update(idx[head[y]],idx[y]+1,z);
                y=par[head[y]];
            }
            else{
                if(x!=y)sg.update(idx[x]+1,idx[y]+1,z);
                break;
            }
        }
    }
	int get(int x,int y){
        if(idx[x]>idx[y])swap(x,y);
        if(head[x]!=head[y]){
            return sg.query(idx[head[y]],idx[y]+1);
        }
        else{
            return sg.query(idx[x]+1,idx[y]+1);
        }
	}
};

struct ppUF{
   vector<int> par,ti;
   vector<vector<pair<int,int>>> his;
   ppUF(int n):ti(n,inf+1),par(n,-1),his(n){
	   for(auto &vs:his)vs.emplace_back(-1,-1);
   }
   int find(int t,int x){
	   if(ti[x]>t)return x;
	   return find(t,par[x]);
   }

   bool unite(int t,int x,int y){
	   x=find(t,x);y=find(t,y);
	   if(x==y)return false;
	   if(par[x]>par[y])swap(x,y);
	   par[x]+=par[y];
	   his[x].emplace_back(t,par[x]);
	   par[y]=x;
	   ti[y]=t;
	   return true;
   }

   bool same(int t,int x,int y){
	   return find(t,x)==find(t,y);
   }
   int time(int x,int y){
	   if(!same(inf,x,y))return -1;
	   int ok=inf,ng=-1,mid=0;
	   while(ok-ng>1){
		   mid=(ok+ng)/2;
		   if(same(mid,x,y))ok=mid;
		   else ng=mid;
	   }
	   return ok;
   }

   int size(int t,int x){
	   x = find(t,x);
	   return -prev(lower_bound(his[x].begin(),his[x].end(),pair<int,int>(t,0)))->second;
   }
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(m),b(m),c(m);
	rep(i,m){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		--a[i];--b[i];
	}
	vector<int> ord(m);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int s,int t){
		return c[s]<c[t];
	});
	ppUF uf(n+1);
	HLDecomposition hl(n);
	vector<ll> ans(m,-1);
	for(auto i : ord){
		if(!uf.same(inf, a[i], b[i])){
			uf.unite(c[i],a[i],b[i]);
			hl.addedge(a[i], b[i]);
		}
		else {
			ans[i]=uf.time(a[i],b[i]);
		}
	}
	hl.build();
	rep(i,m){
		if(ans[i]==-1)continue;
		hl.for_edge(a[i],b[i],c[i]);
	}
	rep(i,m){
		if(ans[i]==-1){
			ans[i]=hl.get(a[i],b[i]);
		}
		printf("%lld\n",ans[i]);
	}
	return 0;
}