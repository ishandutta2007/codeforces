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

const int dx[4] = {0, 0, 1, 1};
const int dy[4] = {0, 1, 0, 1};
char buf[100][100];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", buf[i] + 1);
    int ans = 0;
    for (int i = 1; i <= n - 1; ++i)
        for (int j = 1; j <= m - 1; ++j){
            int tmp = 1;
            for (int k = 0; k < 4; ++k){
                int u = i + dx[k], v = j + dy[k];
                if (buf[u][v] == 'f') tmp *= 2; else 
                    if (buf[u][v] == 'a') tmp *= 3; else 
                        if (buf[u][v] == 'c') tmp *= 5; else
                            if (buf[u][v] == 'e') tmp *= 7;
            }
            if (tmp == 210) ++ans;
        }
    printf("%d\n", ans);
    return 0;
}