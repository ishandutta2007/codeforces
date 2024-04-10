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

// 3-0, 3-1, 3-2
vector<pii>a;
vector<pii>b;
pii dp[205][205][4][4];

void solve(){
	int x,y;
	cin>>x>>y;
	bool good=0;
	for(int i=3;i>-4;i--){
		rep(j,0,4){
			int k=j-i;
			if(k<0 or k>3 or (dp[x][y][j][k].F==0 and  dp[x][y][j][k].S==0) or (j<3 and k<3))continue;
			cout<<j<<":"<<k<<endl;
			vector<pii>ans;
			while(x+y){
				if(dp[x][y][j][k].F){
					if(j+k<5)ans.pb(a[dp[x][y][j][k].F-1]);
					else ans.pb(b[dp[x][y][j][k].F-1]);
					x-=ans.back().F;
					y-=ans.back().S;
					j--;
				}
				else if(dp[x][y][j][k].S){
					if(j+k<5)ans.pb(a[dp[x][y][j][k].S-1]);
					else ans.pb(b[dp[x][y][j][k].S-1]);
					swap(ans.back().F,ans.back().S);
					x-=ans.back().F;
					y-=ans.back().S;
					k--;
				}
			}
			reverse(all(ans));
			for(auto z:ans){
				cout<<z.F<<":"<<z.S<<" ";
			}
			cout<<endl;
			return;
		}
	}
	cout<<"Impossible\n";
}

// dp[i][j][k][l]=dp[i-x][j-y][k-1][l], x>y
// dp[i][j][k][l]=dp[i-x][j-y][k][l-1], x<y

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	rep(i,0,24){
		a.pb(mp(25,i));
	}
	rep(j,26,201){
		a.pb(mp(j,j-2));
	}
	rep(i,0,14){
		b.pb(mp(15,i));
	}
	rep(j,16,201){
		b.pb(mp(j,j-2));
	}

	rep(i,0,205){
		rep(j,0,205){
			rep(k,0,4){
				rep(l,0,4){
					pii& res=dp[i][j][k][l];
					if(i+j+k+l==0)res=mp(-1,-1);
					else if(k==3 and l==3);
					else{
						int idx=1;
						if(k+l!=5){
							for(auto d:a){
								if(i>=d.F and j>=d.S and k and dp[i-d.F][j-d.S][k-1][l]!=mp(0,0) and k-1!=3 and l!=3)res.F=idx;
								if(i>=d.S and j>=d.F and l and dp[i-d.S][j-d.F][k][l-1]!=mp(0,0) and k!=3 and l-1!=3)res.S=idx;
								idx++;
							}
						}
						else{
							for(auto d:b){
								if(i>=d.F and j>=d.S and k and dp[i-d.F][j-d.S][k-1][l]!=mp(0,0) and k-1!=3 and l!=3)res.F=idx;
								if(i>=d.S and j>=d.F and l and dp[i-d.S][j-d.F][k][l-1]!=mp(0,0) and k!=3 and l-1!=3)res.S=idx;
								idx++;
							}
						}
					}
				}
			}
		}
	}
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}