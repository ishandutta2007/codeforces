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
const ll mod = 1000000007;
map<string,int>A;
map<string,int>B;
bool cmp(const string &a,const string &b){
	return a.size() < b.size();
}
int main(){
	int n; cin >> n;
	if(n == 1){
	    cout << "? " << 1 << " " << n << endl;
	    string s; cin >> s;
	    cout << "! " << s << endl;
	    return 0;
	}
	cout << "? " << 2 << " " << n << endl;
	rep(i,(n-1)*n/2){
		string s; cin >> s;
		SORT(s); A[s]++;
	}
	
	cout << "? " << 1 << " " << n << endl;
	rep(i,(n+1)*n/2){
		string s; cin >> s;
		SORT(s); B[s]++;
	}
	vector<string>vec;
	for(auto x:B){
		if(x.sc > A[x.fi]){
			assert(x.sc == A[x.fi]+1);
			vec.pb(x.fi);
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	int pre[26]={};
	string ret = "";
	rep(i,vec.size()){
		int nxt[26]={};
		rep(j,vec[i].size()) nxt[vec[i][j]-'a']++;
		rep(i,26){
			if(nxt[i] > pre[i]){
				assert(nxt[i] == pre[i]+1);
				ret.pb('a'+i);
				break;
			}
		}
		rep(i,26) pre[i] = nxt[i];
	}
	cout << "! " << ret << endl;
}