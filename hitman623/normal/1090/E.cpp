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


pii par[10][10][10][10];
int dist[10][10][10][10];
vector<pii>moves={{-2,-1},{-2,1},{-1,2},{-1,-2},{1,2},{1,-2},{2,-1},{2,1}};
int present[10][10];
int should[10][10];
void solve(){
	memset(dist,1,sizeof dist);
	rep(i,0,10){
		rep(j,0,10){
			rep(k,0,10){
				rep(l,0,10){
					par[i][j][k][l]=mp(-1,-1);
				}
			}
		}
	}
	int k;
	cin>>k;
	rep(i,0,k){
		should[i/8][i%8]=1;
	}
	vector<pii>x;
	rep(i,0,k){
		string s;
		cin>>s;
		x.pb(mp(s[0]-'a',s[1]-'1'));
		swap(x.back().F,x.back().S);
		present[x.back().F][x.back().S]=1;
	}
	sort(all(x));
	rep(i,0,8){
		rep(j,0,8){
			queue<pii>q;
			q.push(mp(i,j));
			dist[i][j][i][j]=0;
			while(!q.empty()){
				auto cur=q.front();
				q.pop();
				for(auto k:moves){
					if(cur.F+k.F>=0 and cur.F+k.F<8 and cur.S+k.S>=0 and cur.S+k.S<8 and dist[i][j][cur.F+k.F][cur.S+k.S]>dist[i][j][cur.F][cur.S]+1){
						par[i][j][cur.F+k.F][cur.S+k.S]=mp(cur.F,cur.S);
						dist[i][j][cur.F+k.F][cur.S+k.S]=dist[i][j][cur.F][cur.S]+1;
						q.push(mp(cur.F+k.F,cur.S+k.S));
					}
				}
			}
		}
	}
	vector<pii> rempos;
	vector<pii> remknights;
	rep(i,0,8){
		rep(j,0,8){
			if(should[i][j]^present[i][j]){
				if(should[i][j])rempos.pb(mp(i,j));
				else remknights.pb(mp(i,j));
			}
		}
	}
	vector<pair<pii,pii>>results;
	rep(i,0,sz(rempos)){
		// target=rempos[i]
		// source=remknights[i]
		vector<pii>path;
		auto cur=remknights[i];
		while(cur!=mp(-1,-1)){
			path.pb(cur);
			cur=par[rempos[i].F][rempos[i].S][cur.F][cur.S];
		}
		vector<bool>z;
		for(auto k:path)
			z.pb(present[k.F][k.S]);
		z.back()=1;
		for(int i=sz(path)-2;i>=0;i--){
			if(!z[i])continue;
			for(int j=i+1;;j++){
				results.pb(mp(path[j-1],path[j]));
				if(z[j])break;
			}
		}
		present[rempos[i].F][rempos[i].S]=1;
		present[remknights[i].F][remknights[i].S]=0;
	}
	assert(sz(results)<=1500);
	cout<<sz(results)<<endl;
	for(auto i:results){
		cout<<char(i.F.S+'a')<<char(i.F.F+'1')<<'-'<<char(i.S.S+'a')<<char(i.S.F+'1')<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}