#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

set <PI> S;
set <int> S2;

int a[N], l[N], r[N];

int main(){
    //freopen("in.txt", "r", stdin);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if (i) S.insert(MP(-abs(a[i] - a[i - 1]), i));
    }

    for (set <PI> :: iterator it = S.begin(); it != S.end(); it++){
        int x = it->second;
        S2.insert(it->second);
        set <int> :: iterator it2 = S2.find(it->second);
        if (it2 == S2.begin()) l[x] = 0;
        else{
            it2--;
            l[x] = *it2;
            it2++;
        }
        it2++;
        if (it2 == S2.end()) r[x] = n;
        else{
            r[x] = *it2;
            it2--;
        }
    }
//    for (int i = 1; i < n; i++)
//        printf("%d ", l[i]);
//    puts("");
//    for (int i = 1; i < n; i++)
//        printf("%d ", r[i]);
//    puts("");

    int x, y;
    while (q--){
        scanf("%d%d", &x, &y);
        LL ans = 0;
        for (int i = x; i < y; i++){
            int L = i - max(x, l[i] + 1);
            int R = min(r[i] - 1, y - 1) - i;
            ans += 1ll * (L+1) * (R+1) * abs(a[i] - a[i - 1]);
        }
        printf("%I64d\n", ans);
    }
}