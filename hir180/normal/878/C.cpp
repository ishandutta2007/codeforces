#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

unsigned long xor128() {
  static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
  unsigned long t=(x^(x<<11));
  x=y; y=z; z=w;
  return ( w=(w^(w>>19))^(t^(t>>8)) );
}

struct node{
	int cnt;
	int sum;
	int w;
	vector<int>mn,mx,valmn,valmx;
	node* ch[2];
	node(){}
	node(vector<int>vi,int ww){
		cnt = 1;
		sum = w = ww;
		mn = mx = valmn = valmx = vi;
		ch[0] = ch[1] = (node*)NULL;
	}
	node(vector<int>a,vector<int>b,vector<int>c,vector<int>d,int ww){
		cnt = 1;
		sum = w = ww;
		mn = a;
		mx = b;
		valmn = c;
		valmx = d;
		ch[0] = ch[1] = (node*)NULL;
	}
};
typedef node* pt;

int get_cnt(pt a){ return !a?0:a->cnt; }
int get_sum(pt a){ return !a?0:a->sum; }
int get_mn(pt a,int i){ return !a?INF:(a->mn)[i]; }
int get_mx(pt a,int i){ return !a?-INF:(a->mx)[i]; }
int get_valmn(pt a,int i){ return !a?0:(a->valmn)[i]; }
int get_valmx(pt a,int i){ return !a?0:(a->valmx)[i]; }
pt update(pt a){
	a->cnt = get_cnt(a->ch[0]) + get_cnt(a->ch[1]) + 1;
	a->sum = get_sum(a->ch[0]) + get_sum(a->ch[1]) + a->w;
	int sz = a->valmn.size();
	rep(i,sz){
		(a->mn)[i] = min(get_valmn(a,i), min(get_mn(a->ch[0],i), get_mn(a->ch[1],i)));
		(a->mx)[i] = max(get_valmx(a,i), max(get_mx(a->ch[0],i), get_mx(a->ch[1],i)));
	}
	return a;
}
pt merge(pt L, pt R){
	if(!L || !R) return !L?R:L;
	
	if(xor128()%(L->cnt+R->cnt) < L->cnt){
		L->ch[1] = merge(L->ch[1], R);
		return update(L);
	}
	else{
		R->ch[0] = merge(L, R->ch[0]);
		return update(R);
	}
}
pair<pt,pt>split(pt t,int k){
	if(!t)  return mp((pt)(NULL),(pt)(NULL));
	
	if(k <= get_cnt(t->ch[0])){
		pair<pt,pt>s = split(t->ch[0],k);
		t->ch[0] = s.sc;
		return mp(s.fi, update(t));
	}
	else{
		pair<pt,pt>s = split(t->ch[1],k-get_cnt(t->ch[0])-1);
		t->ch[1] = s.fi;
		return mp(update(t), s.sc);
	}
}
//vec
int get_lower(pt a,vector<int>vec){
	if(!a) return 0;
	int sz = vec.size();
	bool bad = 0;
	rep(i,sz) if( (a->valmn)[i] < vec[i] ) bad = 1;
	if(!bad){
		return 1 + get_cnt(a->ch[0]) + get_lower(a->ch[1],vec);
	}
	else{
		return get_lower(a->ch[0],vec);
	}
}
//vec
int get_upper(pt a,vector<int>vec){
	if(!a) return 0;
	int sz = vec.size();
	bool ok = 0;
	rep(i,sz) if( (a->valmx)[i] > vec[i] ) ok = 1;
	if(ok){
		return 1 + get_cnt(a->ch[0]) + get_upper(a->ch[1],vec);
	}
	else{
		return get_upper(a->ch[0],vec);
	}
}
void print(node* cur,int val){
    if(cur->ch[0] != (node*)NULL) print(cur->ch[0],val);
    if(cur->ch[1] != (node*)NULL) print(cur->ch[1],val);
}


int n,k;
pt root = (pt)NULL;


int main(){
	scanf("%d%d",&n,&k);
	rep(i,n){
		vector<int>vi;; vi.resize(k);
		rep(j,k) scanf("%d",&vi[j]);
		int L = get_lower(root,vi);
		int R = get_upper(root,vi);
		
		auto a = split(root,R);
		if(L == R){
			root = merge(a.fi, merge(new node(vi, 1), a.sc));
		}
		else{
			auto b = split(a.fi, L);
			vector<int>MN = b.sc -> mn;
			vector<int>MX = b.sc -> mx;
			rep(i,k){
				MN[i] = min(MN[i],vi[i]);
				MX[i] = max(MX[i],vi[i]);
			}
			vector<int>valmn = MN, valmx = MX;
			int w = b.sc -> sum + 1;
			
			root = merge(b.fi, merge(new node(MN,MX,valmn,valmx,w), a.sc));
		}
		
		assert(root->cnt);
		
		auto ans = split(root,1);
		printf("%d\n",ans.fi -> sum);
		root = merge(ans.fi, ans.sc);
		//cout << i << endl;
		//print(root,0);
	}
}