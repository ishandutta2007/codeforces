#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int dx[5] = {0, 1, 1, 1, 2};
const int dy[5] = {0, -1, 0, 1, 0};
int n;
char buf[1000][1000];
bool b[1000][1000];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", buf[i]);
    bool ok = true;
    memset(b, false, sizeof(b));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (buf[i][j] == '#') b[i][j] = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            if (!ok) break;
            if (b[i][j])
                for (int k = 0; k < 5; ++k){
                    int u = i + dx[k], v = j + dy[k];
                    if (u < 0 || u >= n || v < 0 || v >= n){
                        ok = false;
                        break;
                    }
                    if (!b[u][v]){
                        ok = false;
                        break;
                    }
                    b[u][v] = false;
                }
        }
    if (ok) puts("YES"); else puts("NO");
    return 0;
}