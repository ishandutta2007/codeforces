#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Edge{
    int x, y, c;
} e[N];

bool cmp(Edge a, Edge b){
    return a.c < b.c;
}

map <int, int> S;
map <int, int> :: iterator it;

int f[N];



int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].c);
    sort(e + 1, e + m + 1, cmp);
    e[m + 1].c = -1;
    for (int i = 1; i <= m; i++){
        S[e[i].y] = max(S[e[i].y], f[e[i].x] + 1);
        if (e[i].c != e[i + 1].c){
            for (it = S.begin(); it != S.end(); it++) f[it -> first] = max(f[it -> first], it -> second);
            S.clear();
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;

}