/*
LANG: C++
ID: he.andr1
PROG: B
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#include<string>
#include<cstring>
#include<cassert>
#include<numeric>
#include<complex>
#include<cmath>
#include<ctime>

using namespace std;

#define DEBUG 1

#ifdef DEBUG
	#define ERR cerr
#else
	#define ERR if(true); else cerr
#endif

#define ITER(i, v) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++) 
#define X real()
#define Y imag()
#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<int> pt;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }
template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const int MAXN = 200000, L = 1 << 14;

int N;
//stores value, position
stack<pii> values;
//stores position, time
vector<pii> maxTimes;

int size[2 * L];
int minVal[2 * L];

void io(istream &in, ostream &out) {
	in >> N;
    int curMax = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int v; in >> v;
        while(!values.empty() && values.top().A < v) values.pop();
        int t = 0;
        if(!values.empty()) {
            int prev = values.top().B;
            if(prev + 1 == i) t = 1;
            else t = lower_bound(maxTimes.begin(), maxTimes.end(), pii(prev + 1, 0))->B + 1;
        }
        while(!maxTimes.empty() && maxTimes.back().B <= t) maxTimes.pop_back();
        maxTimes.push_back(pii(i, t));
        values.push(pii(v, i));
        setmax(ans, t);
    }
    out << ans << '\n';
}

int main() {
	ifstream fin ("B.in");
	if(fin.good()) {
		ofstream fout ("B.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}