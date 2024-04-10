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

int n,k;
bool bad[1024];
int col[1024];
int use ;
deque<int>que;
bool ask(int a){
	cout << "? " << a+1 << endl;
	string s; cin >> s;
	return s == "Y";
	//bool ret = 0;
	//rep(i,que.size()) ret |= que[i] == col[a];
	//que.push_back(col[a]);
	//if(que.size() == k+1) que.pop_front();
	//use++;
	//return ret;
}
void output(){
	cout<<"R"<<endl;
	//que.resize(0);
}
int answer(int a){
	cout << "! " << a << endl;
	//cout << 3*n*n/2/k << " " << use << endl;
}

int par[1030],ran[1030];
void init(){ for(int i=0;i<1030;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }


int main(){
    init();
	cin >> n >> k;
	//rep(i,n) cin >> col[i];
	if(k == 1){
	rep(i,n){
	    rep(j,i){
	        ask(j);
	        bool f = ask(i);
	        if(f){
	            bad[i] = 1;
	            break;
	        }
	    }
	}goto E;}
	//split into block size k
	for(int i=0;i<n;i++){
		bool flag = ask(i);
		if(flag){
			bad[i] = 1;
		}
	}
	for(int x=k;x<=n/2;x*=2){
		for(int i=0;i<n;i+=2*x){
			//[i, i+x-1]
			//[i+x, i+2*x-1]
			int a = x / k;
			for(int L=0;L<a;L++){
				for(int R=0;R<a;R++){
					//[i+L*k, i+(L+1)*k-1]
					//[i+x+R*k, i+x+(R+1)*k-1]
					output();
					int b1 = i+L*k, b2 = i+x+R*k;
					rep(i,k/2) if(!bad[b1+i]) ask(b1+i);
					rep(i,k/2){
						if(bad[b2+i]) continue;
						bool flag = ask(b2+i);
						if(flag) bad[b2+i] = 1;
					}
					rep(i,k/2){
						if(bad[b1+k/2+i] ) continue;
						bool flag = ask(b1+k/2+i);
						if(flag) bad[b1+k/2+i] = 1;
					}
					output();
					rep(i,k/2) if(!bad[b1+k/2+i]) ask(b1+k/2+i);
					rep(i,k/2){
						if(bad[b2+k/2+i]) continue;
						bool flag = ask(b2+k/2+i);
						if(flag) bad[b2+k/2+i] = 1;
					}
					rep(i,k/2){
						if(bad[b1+i]) continue;
						bool flag = ask(b1+i);
						if(flag) bad[b1+i] = 1;
					}
				}
			}
		}
		//cout << x << " " << use << endl;
	}
	E:;
	int ans = 0;
	for(int i=0;i<n;i++) if(!bad[i]) {ans++;}
	answer(ans);
}