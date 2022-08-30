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
typedef unsigned long long ull;

//A is MP
//B is KMP
struct KMP{
	vector<int>A,B,S;
	int j ;
	void init(int sz){
		A.resize(sz,0);
		B.resize(sz,0);
		S.resize(sz,0);
		A[0] = -1;
		B[0] = -1;
	}
	void update(int pos,int val){
		S[pos] = val;
	}
	void make_MP(int pos){
		j = A[pos];
		while(j >= 0 && S[pos] != S[j]) j = A[j];
		
		j++;
		A[pos+1] = j;
	}
	void make_KMP(int pos){
		j = A[pos];
		while(j >= 0 && S[pos] != S[j]) j = A[j];
		
		j++;
		if(S[pos+1] == S[j]) B[pos+1] = B[j];
		else B[pos+1] =  j;
	}
	vector<int>get_len(int pos){
		int nxt = S[pos+1];
		vector<int>ret;
		pos = B[pos+1];
		
		while(pos > 0){
			ret.pb(pos);
			pos = A[pos];
			if(pos <= 0) break;
			if(S[pos] == nxt) pos = B[pos];
		}
		
		return ret;
	}
}kaede;

struct RMQ{
	int seg[(1<<21)];
	void update(int pos,int v){
		pos += (1<<20)-1;
		seg[pos] = v;
		while(pos > 0){
			pos = (pos-1) / 2;
			seg[pos] = min(seg[pos*2+1], seg[pos*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r < a || b < l  || a > b) return (1<<30)+5;
		if(a <= l && r <= b) return seg[k];
		return min(query(a,b,k*2+1,l,(l+r)/2), query(a,b,k*2+2,(l+r)/2+1,r));
	}
}yui;

ull zan,ans_mod,ans_bit;
vector<int>vec;
void add(ull a){
    int id = 0;
    while(a){
        vec[id++] += a%10;
        a /= 10;
    }
}
void output(){
    bool ok = 0;
    for(int i=0;i<19;i++) if(vec[i] >= 10){
        vec[i+1] += vec[i] / 10;
        vec[i] %= 10;
    }
    for(int x=19;x>=0;x--){
        ok |= !!vec[x];
        if(ok) printf("%d",vec[x]);
    }
    if(!ok) printf("0");
    puts("");
}
int q;
int main(){
	cin >> q;
	kaede.init(600005);
	int id = 0;
	map<int,int,greater<int>>M;
	ull pre = 0;
	bool up = 0;
	vec.resize(20,0);
	while(q--){
		char ch;
		int w;
		scanf(" %c %d",&ch,&w);
		ull x = ans_bit & ((1ull<<30)-1);
		w ^= (int)(x);
		int C = ch-'a';
		C = (C+(int)(ans_mod%26))%26;
		kaede.update(id, C);
		kaede.make_MP(id);
		yui.update(id,w);
		
		if(id){
			if(id > 0) kaede.make_KMP(id-1);
			auto rem_len = kaede.get_len(id-1);
			auto it = M.begin();
			while((*it).fi > w){
				zan -= 1ull * ((*it).fi-w) * (*it).sc;
				M[w] += (*it).sc;
				M.erase(M.find((*it).fi));
				it = M.begin();
			}
			for(auto a:rem_len){
				int v = id-a;
				int x = yui.query(v,id,0,0,(1<<20)-1);
				M[x] --; if(M[x] == 0) M.erase(M.find(x));
				zan -= x;
			}
			if(C == kaede.S[0]) {
				M[w]++;
				zan += w;
			}
			add(zan);
		}
		else{
			M[w]++;
			zan = w;
			add(zan);
		}
		output();
		ans_mod += zan;
		ans_mod %= 26;
		ans_bit += zan;
		id++;
	}
}