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

const int MAXN = 2000;

int N;
int adj[MAXN][MAXN];

int minDist[MAXN][MAXN];

bool isGood() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) minDist[i][j] = 0;
            else if(adj[i][j]) minDist[i][j] = 1;
            else minDist[i][j] = N;
        }
    }
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                setmin(minDist[i][j], minDist[i][k] + minDist[k][j]);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(minDist[i][j] > 2) return false;
        }
    }
    return true;
}

bool dfs(int i = 0, int j = 1) {
    if(j == N) {
        i++, j = i + 1;
        if(j == N) {
            if(isGood()) {
                for(int i = 0; i < N; i++) {
                    for(int j = 0; j < N; j++) { cerr << adj[i][j] << ' '; } cerr << '\n'; }
                return true;
            }
            return false;
        }
    }
    //cerr << N << '\n';
    cerr << i << ' ' << j << '\n';
    adj[i][j] = 1;
    if(dfs(i, j + 1)) return true;
    adj[i][j] = 0;
    adj[j][i] = 1;
    if(dfs(i, j + 1)) return true;
    adj[j][i] = 0;
    return false;
}

const int precomp[6][6] = 
{
{0,1,1,1,0,0},
{0,0,1,1,1,0},
{0,0,0,1,0,1},
{0,0,0,0,1,1},
{1,0,1,0,0,1},
{1,1,0,0,0,0}
};

bool go() {
    if(N == 4) return false;
    if(N % 2 == 0) {
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                adj[i][j] = precomp[i][j];
            }
        }
    }
    /*
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cerr << adj[i][j] << ' '; cerr << '\n';
    }
    cerr << '\n';
    */
    for(int i = N - 2; i >= (N % 2 ? 1 : 6); i-=2) {
        int v1 = i, v2 = i + 1;
        adj[v1][v2] = 1;
        for(int j = 0; j < v1; j++) {
            adj[j][v1] = 1;
            adj[v2][j] = 1;
        }
    }
    return true;
}

void io(istream &in, ostream &out) {
    //N = 6;
    //dfs();
    in >> N;
    //cerr << N << '\n';
    if(go()) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                out << adj[i][j] << ' ';
            }
            out << '\n';
        }
    } else {
        out << -1 << '\n';
    }
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