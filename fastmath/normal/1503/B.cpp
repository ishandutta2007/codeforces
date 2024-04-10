#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
signed main() {
    int n;
    cin >> n;

    V <V <ii> > d(2);
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		d[(i + j)&1].app(mp(i, j));
    	}
    }

    //1 - d[0]
    //2 - d[1]

    FOR (t, n * n) {
    	int c;
    	cin >> c;
    	if (d[0].size() && d[1].size()) {
	    	if (c != 1) {
	    		cout << 1 << ' ' << d[0].back().x << ' ' << d[0].back().y << endl;
	    		d[0].pop_back();
	    	}
	    	else {
	    		cout << 2 << ' ' << d[1].back().x << ' ' << d[1].back().y << endl;
	    		d[1].pop_back();
	    	}    		
    	}
    	else {
    		if (d[0].empty()) {
    			if (c != 2) {
    				cout << 2 << ' ' << d[1].back().x << ' ' << d[1].back().y << endl;
	    			d[1].pop_back();
    			}
    			else {
    				cout << 3 << ' ' << d[1].back().x << ' ' << d[1].back().y << endl;
	    			d[1].pop_back();    				
    			}
    		}
    		else {
    			if (c != 1) {
    				cout << 1 << ' ' << d[0].back().x << ' ' << d[0].back().y << endl;
	    			d[0].pop_back();
    			}
    			else {
    				cout << 3 << ' ' << d[0].back().x << ' ' << d[0].back().y << endl;
	    			d[0].pop_back();  				
    			}
    		}
    	}
    }
}