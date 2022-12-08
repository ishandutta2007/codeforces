#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef long long int64;
typedef unsigned long long qword;
typedef unsigned int uint;

const int INFI_INT = 1<<30;
const int64 INFI_INT64 = (int64)(1<<30) * (int64)(1<<30);
const double PI = acos(-1);

template <class T> T sqr(T x) { return x * x; }
template <class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template <class T> T absval(T x) { return x > 0 ? x : -x; }

#define forint(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define forintdown(i, s, t) for (int i = (int)(s); i >= (int)(t); -- i)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define movechar(a, b) memmove(b, a, sizeof(a))

const int maxn = 100010;
const int maxlog = 20;

pair<int, int> hash[maxn][maxlog];
char a[maxn];
int n, ind;

void precount() {
    forint (i, 0, n-1)
        hash[i][0] = make_pair(a[i]*3, a[i]*5);
    int p1 = 151, p2 = 233;
    int q1 = 1000000007, q2 = 100000009;
    for (int w = 1, j = 1; w*2 <= n; ++ j, w *= 2) {
        forint (i, 0, n-w-1) {
            hash[i][j].first = (int)(((int64)hash[i][j-1].first * (int64)p1 + (int64)hash[i+w][j-1].first) % q1);
            hash[i][j].second = (int)(((int64)hash[i][j-1].second * (int64)p2 + (int64)hash[i+w][j-1].second) % q2);
        }
        p1 = ((int64)p1 * (int64)p1) % q1;
        p2 = ((int64)p2 * (int64)p2) % q2;
    }
   //forint(j,0,2)forint (i,0,n-1)
   //         printf("hash[%d][%d] = %d\n", i, j, hash[i][j].first);
}

struct Item {
    int i, j;
    friend bool operator <(const Item &ca, const Item &cb) {
        int i1 = ca.i, j1 = ca.j;
        int i2 = cb.i, j2 = cb.j;
        for (int k = maxlog-1, w = 1<<k; w > 0; w /= 2, -- k)
            if (i1+w-1 <= j1 && i2+w-1 <= j2 && hash[i1][k] == hash[i2][k])
                i1 += w, i2 += w;
        if (i1 > j1) return true;
        if (i2 > j2) return false;
        return a[i1] < a[i2];
    }
};

void solve() {
    scanf("%s%d", a, &ind);
    n = strlen(a);
    if ((int64)ind > (int64)n*(int64)(n+1)/2) {
        printf("No such line.\n");
        return;
    }
    precount();
    set<Item> basket;
    forint (i, 0, n-1) {
        Item it;
        it.i = it.j = i;
        basket.insert(it);
    }
    forint (i, 1, ind-1) {
        Item it = *basket.begin();
        basket.erase(basket.begin());
        /*
    printf("rank=%d  ", i);
    forint (i, it.i, it.j)
        printf("%c", a[i]);
    printf("\n");*/
        ++ it.j;
        if (it.j <= n-1)
            basket.insert(it);
    }
    Item it = *basket.begin();
    forint (i, it.i, it.j)
        printf("%c", a[i]);
    printf("\n");
}

int main() {
    /*
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
    //*/
   // while(1)
    solve();
    return 0;
}