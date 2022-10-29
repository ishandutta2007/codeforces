#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

string to_string(string s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(char ch) {
	return string("'")+ch+string("'");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <class InputIterator>
string to_string (InputIterator first, InputIterator last) {
	bool start = true;
	string res = "{";
	while (first!=last) {
		if (!start) {
			res += ", ";
		}
		start = false;
		res += to_string(*first);
		++first;
	}
	res += "}";
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x){
	input>>x.F>>x.S;
	return input;
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x){
	for(auto& i:x)
		input>>i;
	return input;
}


#ifdef PRINTERS
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int dp[10][10];
void solve(){
	int n=9;
	cin>>n;
	rep(i,1,n+1){
		rep(j,1,n+1){
			cin>>dp[i][j];
			// dp[i][j]=0;
		}
	}
	rep(i,1,n+1)dp[i][i]=1;
	rep(i,1,n+1){
		rep(j,1,n+1){
			rep(k,1,n+1){
				dp[j][k]|=(dp[j][i]&dp[i][k]);
			}
		}
	}
	vi dsu(n+1,-1);
	rep(i,1,n+1){
		rep(j,1,n+1){
			if(dp[i][j] and dp[j][i]){
				int a=i;
				int b=j;
				while(dsu[a]>0)a=dsu[a];
				while(dsu[b]>0)b=dsu[b];
				if(a==b)continue;
				if(dsu[a]>dsu[b])swap(a,b);
				dsu[a]+=dsu[b];
				dsu[b]=a;
			}
		}
	}
	vector<vector<string>>v(25,vector<string>(5));
	rep(i,0,25){
		if(i%2){
			rep(j,0,5)v[i][j]=string(5000,'#');
		}
		else{
			rep(j,0,5)v[i][j]=string(5000,'.');
		}
	}
	map<int,set<int>>m;
	rep(i,1,n+1){
		if(dsu[i]<0)m[i]={};
	}
	map<int,int>indeg;
	rep(i,1,n+1){
		rep(j,1,n+1){
			if(dp[i][j] and !dp[j][i]){
				int a=i;
				int b=j;
				while(dsu[a]>0)a=dsu[a];
				while(dsu[b]>0)b=dsu[b];
				if(m[a].count(b))continue;
				m[a].insert(b);
				indeg[b]++;
			}
		}
	}
	vector<int>topo;
	queue<int>q;
	for(auto i:m){
		if(indeg.count(i.F)==0)q.push(i.F);
	}
	while(!q.empty()){
		topo.pb(q.front());
		q.pop();
		for(auto i:m[topo.back()]){
			indeg[i]--;
			if(indeg[i]==0)q.push(i);
		}
	}
	for(auto i:m)debug(i.F,i.S);
	debug(topo);
	vi layer(n+1);
	rep(i,0,sz(topo)) layer[topo[i]]=2*i;
	int tunnel=3;
	rep(i,0,sz(topo)){
		int node=topo[i];
		for(auto j:m[node]){
			for(int k=layer[node];k<layer[j];k+=2){
				v[k+1][2][tunnel]='.';
				if(k!=layer[node]){
					v[k][2][tunnel-1]='#';
					v[k][2][tunnel+1]='#';
					v[k][1][tunnel-1]='#';
					v[k][1][tunnel+1]='#';
					v[k][3][tunnel-1]='#';
					v[k][3][tunnel+1]='#';
					v[k][1][tunnel]='#';
					v[k][3][tunnel]='#';
				}
			}
			tunnel+=4;
		}
	}
	rep(i,1,n+1){
		int u=i;
		while(dsu[u]>0)u=dsu[u];
		int idx=layer[u];
		bool done=0;
		for(auto& j:v[idx]){
			if(done)break;
			for(auto& k:j){
				if(done)break;
				if(k=='.'){
					k='0'+i;
					done=1;
				}
			}
		}
	}
	cout<<5000<<" "<<5<<" "<<25<<endl;
	rep(i,0,25){
		rep(j,0,5)cout<<v[i][j]<<endl;
		cout<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}