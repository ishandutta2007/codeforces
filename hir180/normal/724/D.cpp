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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int m;
vector<int>pos[26];
string s,t;

int main(){
	cin >> m >> s;
	rep(i,s.size()) pos[s[i]-'a'].pb(i);
	t = s; SORT(t);
	set<int>S; S.insert(s.size());
	for(int i=0;i<26;i++){
		rep(j,pos[i].size()) S.insert(pos[i][j]);
		int pre = -1, bad = 0;
		for(auto a:S){
			if(a-pre-1 >= m) {
				bad = 1; break;
			}
			pre = a;
		}
		if(bad) continue;
		rep(j,pos[i].size()) S.erase(S.find(pos[i][j]));
		vector<P>vec;
		pre = -1;
		for(auto a:S){
			if(a-pre-1 >= m) vec.pb(P(pre+1,a-1));
			pre = a;
		}
		int ub = 0;
		rep(x,vec.size()){
			int a = vec[x].fi, b = vec[x].sc;
			while(b-a+1 >= m){
			   // cout << a << " " << b << endl;
				int k = POSL(pos[i],a+m);
				a = pos[i][k-1]+1;
				ub++;
			}
		}
		
		rep(j,t.size()){
			if(t[j] >= 'a'+i) break;
			printf("%c",t[j]);
		}
		rep(x,ub) printf("%c",'a'+i);
		puts("");
		return 0;
	}
	assert(false);
}