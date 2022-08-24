#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    int n, m, k, p;
    scanf("%d%d%d%d", &n, &m, &k, &p);
    vector<int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int x;
            scanf("%d", &x);
            a[i] += x;
            b[j] += x;
        }
    }
    LL ans = -1000000000000000000;
    vector<LL> s(k + 1, 0), t(k + 1, 0);
    multiset<LL> ss;
    for (int i = 0; i < n; i++) ss.insert(-a[i]);
    for (int i = 1; i <= k; i++){
        multiset<LL>::iterator it = ss.begin();
        s[i] = s[i - 1] - *it;
        LL x = *it + p * m;
        ss.erase(it);
        ss.insert(x);
    }
    ss.clear();
    for (int i = 0; i < m; i++) ss.insert(-b[i]);
    for (int i = 1; i <= k; i++){
        multiset<LL>::iterator it = ss.begin();
        t[i] = t[i - 1] - *it;
        LL x = *it + p * n;
        ss.erase(it);
        ss.insert(x);
    }
    for (int i = 0; i <= k; i++){
        ans = max(ans, s[i] + t[k - i] - 1ll * p * i * (k - i));
    }
    cout << ans << "\n";
    
    return 0;
}