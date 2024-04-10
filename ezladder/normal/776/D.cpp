#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>

using namespace std;

typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define XX first
#define YY second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
const double pi = acos(-1.0);

const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

/*
const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

struct cnm {
    int pred, ra;
    cnm() {};
};

int n, m;
int color[100007];
vector<int> t[100007];
vector<int> g[100007];
int col[100007];
cnm d[100007];
bool was[100007];

int get(int v){
    if (d[v].pred == v) return v;
    d[v].pred = get(d[v].pred);
    return d[v].pred;
}

void merge(int a, int b){
    a = get(a);
    b = get(b);
    if (a != b){
        if (d[a].ra < d[b].ra) swap(a, b);
        d[b].pred = a;
        if (d[b].ra == d[a].ra) d[a].ra++;
    }
}

void dfs(int v, int cc){
    if (was[v]){
        if (col[v] != -1 && col[v] != cc)
            cout << "NO", exit(0);
        return;
    }
    was[v] = 1;
    col[v] = cc;
    for (int to : g[v]){
        dfs(to, cc ^ 1);
    }
}

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //mt19937 rnd(time(NULL));

    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("integral.in", "r", stdin);
        //freopen("integral.out", "w", stdout);
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 100007; i++) d[i].pred = i, d[i].ra = 0, col[i] = -1;
    for (int i = 0; i < n; i++) scanf("%d", &color[i]);
    for (int i = 0; i < m; i++){
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++){
            int x;
            scanf("%d", &x); x--;
            t[x].pub(i);
        }
    }
    for (int i = 0; i < n; i++){
        int a = t[i][0], b = t[i][1];
        if (color[i] == 1) merge(a, b);
    }
    for (int i = 0; i < n; i++){
        int a = t[i][0], b = t[i][1];
        if (color[i] == 0){
            a = get(a);
            b = get(b);
            if (a == b) cout << "NO", exit(0);
            g[a].pub(b);
            g[b].pub(a);
        }
    }
    for (int i = 0; i < 100007; i++)
        if (!was[i])
            dfs(i, 0);
    cout << "YES";
}