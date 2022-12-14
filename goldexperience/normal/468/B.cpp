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

const int maxn = 111111;
int n, A, B;
int c[maxn], q[maxn], kind[maxn], o[maxn];
bool b[maxn];
set<int> S;

int main(){
    scanf("%d%d%d", &n, &A, &B);
    for (int i = 0; i < n; ++i){
        scanf("%d", &c[i]);
        o[i] = c[i];
        b[i] = false;
    }
    sort(c, c + n);
    for (int i = 0; i < n; ++i)
        if (!b[i]){
            int l = 1, r = 1;
            q[l] = i;
            b[i] = true;
            while (l <= r){
                int now = c[q[l]];
                int t = lower_bound(c, c + n, A - now) - c;
                if (t < n && c[t] == A - now && !b[t]){
                    b[t] = true;
                    q[++r] = t;
                }
                t = lower_bound(c, c + n, B - now) - c;
                if (t < n && c[t] == B - now && !b[t]){
                    b[t] = true;
                    q[++r] = t;
                }
                ++l;
            }

            S.clear();
            for (int j = 1; j <= r; ++j) S.insert(c[q[j]]);
            bool Find = false;
            for (int j = 0; j < 2; ++j){
                int t = j == 0 ? A : B;
                bool ff = true;
                for (int k = 1; k <= r; ++k)
                    if (S.find(t - c[q[k]]) == S.end()){
                        ff = false;
                        break;
                    }
                if (ff){
                    for (int k = 1; k <= r; ++k)
                        kind[q[k]] = j;
                    Find = true;
                    break;
                }
            }
            if (!Find){
                puts("NO");
                return 0;
            }

        }
    puts("YES");
    for (int i = 0; i < n; ++i){
        if (i) putchar(' ');
        int t = lower_bound(c, c + n, o[i]) - c;
        printf("%d", kind[t]);
    }
    printf("\n");
    return 0;
}