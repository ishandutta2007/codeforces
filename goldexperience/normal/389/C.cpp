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

int n;
int c[10000], b[10000];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &c[i]);
    sort(c, c + n);
    for (int ans = 1; ans <= n; ++ans){
        bool ok = true;
        for (int i = 0; i < ans; ++i)
            b[i] = 101;
        for (int i = n - 1; i >= 0; --i){
            int k = 0;
            for (int j = 0; j < ans; ++j)
                if (b[j] > b[k]) k = j;
            if (b[k] == 0){
                ok = false;
                break;
            }
            b[k] = min(b[k] - 1, c[i]);
        }
        if (ok){
            printf("%d\n", ans);
            break;
        }
    }
    return 0;
}