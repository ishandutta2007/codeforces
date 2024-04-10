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

void solve(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,set<int>>>x(n);
	int cnt=0;
	rep(i,0,n){
		x[i].F=i;
		int p;
		cin>>p;
		cnt+=p;
		rep(j,0,p){
			int temp;
			cin>>temp;
			x[i].S.insert(temp);
		}
	}
	sort(all(x),[](auto a,auto b){return sz(a.S)>sz(b.S);});
	vi reqd(n);
	rep(i,0,n){
		reqd[i]=cnt/n+(cnt%n>i);
	}
	// debug(reqd);
	vector<pair<pii,int>> moves;
	int p2=n-1;
	rep(i,0,n){
		while(sz(x[i].S)!=reqd[i]){
			while(p2>=i and sz(x[p2].S)==reqd[p2]) p2--;
			if(p2<=i) break;
			int del=min(sz(x[i].S)-reqd[i],-sz(x[p2].S)+reqd[p2]);
			vi removed;
			for(auto j:x[i].S){
				if(del==0) break;
				if(x[p2].S.count(j)==0){
					x[p2].S.insert(j);
					removed.pb(j);
					del--;
					moves.pb({{x[i].F,x[p2].F},j});
				}
			}
			for(auto j:removed){
				x[i].S.erase(j);
			}
		}
	}
	cout<<sz(moves)<<endl;
	for(auto i:moves){
		cout<<i.F.F+1<<" "<<i.F.S+1<<" "<<i.S<<endl;
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