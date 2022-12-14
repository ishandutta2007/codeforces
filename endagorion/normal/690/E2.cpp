#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cout << "2 1\n2 3 1\n4 3 2 1\n1 3 4 2 5\n1 6 15 3 14 9 13 10 7 11 2 5 4 12 8\n5 1 3 11 10 7 6 9 13 15 12 4 14 2 8\n9 7 2 5 1 10 8 3 4 6\n2 1 4 3\n4 12 8 2 9 14 5 7 1 6 10 13 15 3 11\n11 5 6 8 10 12 7 2 1 4 9 3 13 14 15\n5 1 2 13 14 9 7 8 12 3 6 11 10 4 15\n12 7 11 4 10 2 5 14 13 1 6 3 9 8 15 16\n3 2 1\n4 2 1 3 5\n1 8 11 15 3 2 7 16 13 4 6 10 9 12 5 14\n9 8 6 13 11 10 2 7 14 12 5 4 15 3 1\n11 6 7 9 16 14 8 12 2 1 10 5 3 13 15 4\n15 5 2 14 3 13 1 7 12 8 4 10 6 11 9\n9 7 3 15 2 12 13 5 1 14 11 10 8 4 6\n9 7 13 10 15 16 5 3 6 1 2 11 8 4 14 12\n6 13 2 11 5 10 3 14 9 1 12 8 16 4 15 7\n11 15 9 7 6 1 13 3 16 5 4 10 14 2 12 8\n2 1 5 13 6 11 9 8 4 3 7 14 10 12 15\n3 11 4 5 14 10 16 9 8 6 7 13 12 1 15 2\n4 3 11 9 8 16 6 15 2 13 7 14 10 1 12 5\n1 12 9 7 6 5 2 13 14 10 15 8 11 4 3\n2 1 3\n2 1\n1 3 2 6 4 8 7 5\n14 7 8 6 2 9 13 4 1 5 11 15 16 10 3 12\n1 7 4 3 6 5 2 8\n13 7 6 14 12 15 3 5 1 9 8 10 4 11 2\n11 2 15 5 14 3 9 10 7 1 12 13 8 6 4\n4 2 3 1\n16 13 11 14 9 2 15 3 1 5 6 7 12 8 4 10\n3 1 4 9 16 15 7 10 6 13 5 11 2 14 12 8\n14 16 13 4 9 10 12 8 7 11 3 5 15 6 2 1\n3 1 6 5 2 4\n14 8 2 10 6 16 9 7 15 4 1 3 11 13 5 12\n15 8 10 9 11 12 7 13 5 14 1 4 3 2 6\n5 7 3 12 6 11 8 4 10 1 2 9\n2 1\n13 14 8 6 4 7 5 10 3 11 2 9 15 12 1\n2 15 11 13 12 5 3 4 9 8 14 6 10 1 7\n3 1 4 2\n6 2 16 5 7 10 15 1 8 14 13 4 9 11 3 12\n3 1 2\n16 4 13 11 7 9 5 2 10 3 6 15 12 14 8 1\n2 5 1 9 15 7 3 11 13 4 8 12 6 14 10\n6 3 10 14 11 15 7 2 5 16 4 13 8 1 12 9\n5 7 11 3 10 15 2 9 4 8 14 13 16 12 1 6\n4 5 6 7 11 3 10 16 12 15 14 2 1 8 13 9\n6 5 2 10 12 8 4 13 9 11 1 15 3 14 7\n12 13 9 1 3 11 4 8 16 14 10 7 15 5 6 2\n4 2 3 1\n10 3 15 1 12 2 11 5 16 4 13 9 14 8 7 6\n6 3 1 5 2 4\n2 14 9 7 8 3 4 5 6 13 10 1 11 12 15\n10 8 2 11 15 5 1 13 16 12 14 9 6 4 3 7\n8 2 15 11 9 12 16 6 13 7 4 5 14 1 10 3\n3 9 10 13 6 16 5 4 8 7 12 11 1 15 14 2\n3 2 1 12 5 15 6 4 9 13 8 7 14 11 10\n6 7 3 2 5 8 1 9 10 4\n9 6 8 5 12 7 10 3 11 1 13 14 15 4 16 2\n8 1 13 15 7 10 5 9 3 2 6 4 12 11 14\n12 6 11 14 2 1 4 8 10 16 15 7 3 9 5 13\n3 2 1\n4 7 8 2 1 6 5 3\n2 1\n1 10 14 13 5 11 8 12 16 9 15 6 3 7 2 4\n15 9 2 8 1 4 14 13 5 3 12 6 7 11 10\n4 1 5 2 3\n2 6 3 11 9 7 8 5 4 1 10 12\n2 13 7 3 5 15 12 9 10 16 11 4 8 1 6 14\n10 9 5 14 8 4 6 3 1 12 13 7 2 11 16 15\n11 16 14 2 6 12 3 4 1 8 7 13 10 9 15 5\n15 14 4 6 9 5 3 2 13 12 10 11 7 1 8\n13 10 15 11 4 16 2 3 14 9 5 6 8 7 12 1\n4 3 5 14 6 8 16 10 9 12 2 11 13 15 7 1\n1 4 5 10 9 6 8 3 2 7\n7 6 15 5 12 13 2 4 3 14 11 1 10 8 9\n2 14 9 3 8 7 6 15 10 11 16 5 12 13 1 4\n2 5 9 1 11 4 16 6 8 7 12 3 13 10 15 14\n3 5 7 14 1 9 6 4 10 8 11 15 2 16 12 13\n6 5 1 4 8 12 9 3 11 2 15 16 13 14 10 7\n6 1 4 16 2 9 8 5 12 11 10 13 3 7 14 15\n16 14 9 8 4 1 7 2 12 10 3 5 11 6 15 13\n6 1 5 2 4 3\n3 10 4 5 9 6 1 2 7 8\n8 1 15 10 12 5 14 11 4 2 3 13 7 9 6\n5 13 12 7 9 1 10 4 15 8 3 2 14 6 11\n2 3 6 1 4 5\n3 15 13 6 7 11 12 1 14 4 8 9 2 10 5\n13 7 8 6 16 12 15 14 3 10 11 9 1 4 5 2\n7 2 4 13 9 1 15 8 12 11 6 3 5 14 10\n3 4 5 6 14 8 9 10 15 12 11 13 7 2 1\n4 11 5 12 8 14 10 7 3 9 16 13 15 1 6 2\n2 6 3 1 4 5\n6 5 7 9 2 8 3 1 4 10\n14 7 15 11 1 4 3 13 5 10 6 9 8 2 12\n15 14 5 3 7 4 1 9 11 6 10 2 12 13 8\n16 14 3 7 13 2 6 1 10 12 9 4 5 8 11 15\n3 8 5 10 12 11 4 6 7 9 2 1\n11 3 5 4 12 8 1 2 6 7 9 10\n3 11 6 16 13 15 5 2 12 7 14 8 10 9 4 1\n6 5 1 4 3 2\n1 4 2 10 12 11 9 5 6 13 3 14 15 8 7\n1 13 10 6 3 12 7 4 8 5 15 11 2 9 14\n12 5 7 8 1 9 10 15 6 4 14 13 3 2 11\n2 5 3 9 13 4 7 12 6 14 10 11 15 1 8\n5 4 2 6 1 3\n4 8 9 1 5 13 11 7 3 12 2 6 14 15 10\n2 1\n11 5 7 9 15 2 8 14 3 13 10 12 1 6 4\n5 14 15 4 13 6 8 10 7 12 2 11 16 3 9 1\n12 8 7 2 3 9 15 5 11 6 4 14 13 1 10\n14 7 11 13 2 3 12 1 10 9 5 8 4 15 6\n6 4 3 5 1 2 7 8\n1 9 13 4 6 14 11 7 2 15 12 8 5 10 3 16\n3 5 1 8 2 9 7 12 4 11 10 6\n2 5 4 9 11 12 13 6 3 1 15 10 8 7 14\n13 6 8 11 12 15 1 2 10 9 7 14 3 5 4\n2 11 15 12 5 8 9 1 14 10 4 3 6 7 13\n5 8 16 3 10 6 14 7 1 15 12 9 13 2 11 4\n10 12 1 16 11 4 2 15 6 7 13 14 5 3 8 9\n1 2 5 3 4\n6 5 1 4 2 3\n8 4 7 5 6 1 2 3\n4 2 3 1\n4 5 6 10 3 1 2 9 8 7\n1 8 10 12 14 13 16 11 9 4 3 2 7 5 15 6\n2 1\n1 10 3 2 13 4 11 9 5 14 12 6 7 15 8\n15 13 8 2 7 11 6 5 14 9 10 12 3 4 1\n2 1\n8 4 5 10 6 1 14 13 12 9 2 3 11 15 7\n10 3 6 8 5 11 14 16 7 1 9 2 13 4 15 12\n7 5 6 2 4 1 8 3\n10 2 7 9 11 6 1 8 3 5 12 4\n4 2 3 1\n3 13 9 7 11 15 14 10 5 2 16 12 4 8 1 6\n1 6 10 4 15 5 3 13 7 12 9 2 8 11 14\n2 7 14 16 13 8 3 15 12 11 1 4 6 5 10 9\n4 3 1 2 5\n3 4 11 7 15 1 13 10 9 14 16 12 5 8 2 6\n4 9 14 7 12 3 10 5 13 1 2 11 8 6 15\n10 9 16 13 7 3 12 4 15 8 5 1 11 2 6 14\n2 1\n14 4 1 2 13 6 3 5 12 10 7 9 15 8 11\n3 4 1 6 2 5\n5 10 4 6 2 8 11 9 1 7 3 13 15 14 12\n2 4 1 3\n16 14 12 11 7 3 2 6 1 9 4 10 15 13 5 8\n13 14 1 4 11 15 2 12 5 8 10 9 6 16 7 3\n4 2 1 3\n7 10 3 4 1 12 13 6 9 15 14 2 11 5 8\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}