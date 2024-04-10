#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int a[2000][2000];

bool cmp(const PII &x, const PII &y) {
    return a[x.first][x.second] > a[y.first][y.second];
}

VI r[2000], c[2000];
bool ok[2000 * 2000];

int main() {
    int n, m;
    vector<PII> res;
    cin >> n >> m;
    REP(i, n) REP(j, m) scanf("%d", &a[i][j]);
    REP(i, n) REP(j, m) res.PB(MP(i, j));
    sort(ALL(res), cmp);
    TR(it, res) {
        int x = it->first, y = it->second;
        TR(it, r[y]) {
            TR(it2, c[x]) {
                if (ok[*it * 1100 + *it2]) {
                    cout << a[x][y] << endl;
                    return 0;
                }
            }
        }
        ok[x * 1100 + y] = true;
        r[y].PB(x);
        c[x].PB(y);
    }
}