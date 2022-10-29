#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ll;

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 111111;

int n, id;
string s;
vi nxt, prv;
set<int> g;

int main() {

    cin >> s;
    n = s.size();
    nxt.resize(n);
    prv.resize(n);
    forn(i, n) {
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }
    prv[0] = -1;
    nxt[n - 1] = -1;

    forn(i, n - 1) {
        if (s[i] == s[nxt[i]])
            g.insert(i);
    }

    if (n & 1) {
        cout << "No";
        return 0;
    }

    while (!g.empty()) {
        id = *g.begin();
        g.erase(id);
        g.erase(nxt[id]);
        int nid = prv[id];
        if (nid != -1) {
            g.erase(nid);
            nxt[nid] = nxt[nxt[id]];
            prv[nxt[nxt[id]]] = nid;
            if (s[nid] == s[nxt[nid]])
                g.insert(nid);
        }
        if (nxt[nxt[id]] != -1)
            prv[nxt[nxt[id]]] = nid;

        n -= 2;
    }

    cout << (n == 0 ? "Yes" : "No");

	return 0;
}