//#include "stdafx.h"
/*
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
#include <cstdalign>
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
*/





#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };



class CentroidTree {
public:
	int n; //_
	vii G; //OtXg\
	vector<bool> isused; //_g
	vi subtreesize; //TCY,XV
	vi parent;
	vi centroid; //dS
	vector<char> ans;

	CentroidTree(int n) : n(n) {
		G.resize(n); isused.resize(n); 
		subtreesize.resize(n); parent.resize(n);
		ans.resize(n);
	}

	void add_edge(int u, int v) {
		G[u].push_back(v); G[v].push_back(u);
	}
	
	int search_centroid(int now, int par, int size) {
		subtreesize[now] = 1;
		parent[now] = par;
		bool iscentroid = true;
		for (int i = 0; i < G[now].size(); i++) {
			int child = G[now][i];
			if (child == par) continue;
			if (isused[child]) continue;
			int child_size = search_centroid(child, now, size);
			if (child_size > size / 2) iscentroid = false;
			subtreesize[now] += child_size;
		}
		if (size - subtreesize[now] > size / 2) {
			iscentroid = false;
		}
		if (iscentroid) {
			centroid.push_back(now);
		}
		return subtreesize[now];
	}

	//
	void solve(int root, char c, int size) {
		search_centroid(root, -1, size);
		int cent = centroid.back();
		isused[cent] = true;
		ans[cent] = c;
		rep(i, G[cent].size()) {
			int ch = G[cent][i];
			if (isused[ch]) {
				continue;
			}
			if (parent[ch] == cent) {
				solve(ch, c + 1, subtreesize[ch]);
			}
			else {
				solve(ch, c + 1, size - subtreesize[cent]);
			}
		}
		return;
	}

	
};

int main() {
	int n;
	cin >> n;
	CentroidTree tree(n);
	rep(i, n - 1) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		tree.add_edge(u, v);
	}
	tree.solve(0, 'A', n);
	rep(i, n) {
		cout << tree.ans[i] << " ";
	}
	cout << endl;
}