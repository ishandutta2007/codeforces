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

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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

#ifdef PRINTERS
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
#define base1 1000003
#define base2 1000033
vi x;
vi y;
vi z;
pair<ll,ll> fhash[400005],bhash[400005],pwr[400005];
void pre(){
	int i,c;
	pair<ll,ll> h={0,0};
	for(i=1,pwr[0]={1,1};i<=400000;i++){
		pwr[i].F=(pwr[i-1].F*base1);
		pwr[i].S=(pwr[i-1].S*base2);
	}
	for(i=0;i<sz(y);i++){
		c=y[i];
		h.F=h.F*base1+c+1;
		h.S=h.S*base2+c+1;
		fhash[i]=h;
	}
	h={0,0};
	for(i=sz(y)-1;i>=0;i--){
		c=y[i];
		h.F=h.F*base1+c+1;
		h.S=h.S*base2+c+1;
		bhash[i]=h;
	}
}
pair<ll,ll> getf(int l,int r){
	if(l==0)
		return fhash[r];
	return {fhash[r].F-fhash[l-1].F*pwr[r-l+1].F,fhash[r].S-fhash[l-1].S*pwr[r-l+1].S};
}
pair<ll,ll> getb(int l,int r){
	if(r==sz(y)-1)
		return bhash[l];
	return {bhash[l].F-bhash[r+1].F*pwr[r-l+1].F,bhash[l].S-bhash[r+1].S*pwr[r-l+1].S};
}
bool isPalin(int l,int r){
	if(l>r)return true;
	return getf(l,r)==getb(l,r);
}

void solve(){
	int N,M;
	cin>>N>>M;
	vi temp(N);
	rep(i,0,N)cin>>temp[i];
	x.resize(N+N);
	rep(i,0,N){
		x[i+N]=x[i]=(temp[(i+1)%N]-temp[i]+M)%M;
	}
	z=x;
	sort(all(z));
	z.resize(unique(all(z))-z.begin());
	y=x;
	for(auto& i:y){
		i=lower_bound(all(z),i)-z.begin();
	}
	pre();
	debug(x);
	debug(y);
	set<int>s;
	// rep(i,0,N){
	// 	if(isPalin(i,i-1+N))s.insert((2LL*temp[i])%M);
	// 	if(x[i]%2==0 and isPalin(i+1,i-1+N))s.insert((2LL*temp[i]+x[i])%M);
	// }
	if(temp[0]==0){
		rep(i,0,N){
			if(isPalin(0,i-1) and isPalin(i,N-1))s.insert(temp[i]);
		}
	}
	else{
		rep(i,0,N){
			if(x[i]==x[N-1]){
				if(isPalin(0,i-1) and isPalin(i,N-1))s.insert((temp[i]+temp[0])%M);
			}
		}
	}
	cout<<sz(s)<<endl;
	for(auto i:s)cout<<i<<" ";
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