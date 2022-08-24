#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    int n = nxt();
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        a[i].x = nxt();
        a[i].y = nxt();
    }
    sort(all(a));
    vector<int> d(n + 1);
    for (int i = 0; i < n; i++){
        pair<int, int> p = {a[i].first - a[i].second, 0};
        int pos = lower_bound(all(a), p) - a.begin();
        d[i + 1] = d[pos] + i - pos;
    }
    int ans = n;
    for (int i = 0; i < n; i++){
        ans = min(ans, n - i - 1 + d[i + 1]);
    }
    printf("%d\n", ans);

    return 0;
}