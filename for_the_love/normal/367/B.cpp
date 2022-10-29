#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 444444;

int cnt[N], num[N], a[N], b[N];

long long n, m, p;



int main(){
    //scanf("%d%d%d", &n, &m, &p);
    cin >> n >> m >> p;
    vector <int> vec;
    map <int, int> S;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        vec.push_back(a[i]);
    }
    for (int i = 1; i <= m; i++){
        scanf("%d", &b[i]);
        vec.push_back(b[i]);
    }
    sort(vec.begin(), vec.end());
    int t = 1;
    S[vec[0]] = 1;
    for (int i = 1; i < vec.size(); i++){
        if (vec[i] != vec[i - 1]) t++;
        S[vec[i]] = t;
    }
    for (int i = 1; i <= n; i++) a[i] = S[a[i]];
    for (int i = 1; i <= m; i++){
        b[i] = S[b[i]];
        num[b[i]]++;
    }
    int tot = 0;
    for (int i = 0; i < N; i++)
    if (num[i]) tot++;

    vector <int> ans;
    for (int s = 1; s <= p; s++){
        if (s + (m - 1) * p > n) continue;
        int t = 0;
        for (int i = 0; i < m; i++){
            int x = a[i * p + s];
            if (cnt[x] == num[x]) t--;
            cnt[x]++;
            if (cnt[x] == num[x]) t++;
        }
        if (t == tot) ans.push_back(s);
        long long last = s + (m - 1) * p;
        for (int i = 1; s + (m - 1 + i) * p <= n; i++){
            int x = a[(i - 1) * p + s];
            if (cnt[x] == num[x]) t--;
            cnt[x]--;
            if (cnt[x] == num[x]) t++;

            x = a[s + (m - 1 + i) * p];
            if (cnt[x] == num[x]) t--;
            cnt[x]++;
            if (cnt[x] == num[x]) t++;
            if (t == tot) ans.push_back(s + i * p);
            last = s + (m - 1 + i) * p;
        }
        for (int i = 0; i < m; i++) cnt[a[last - p * i]]--;
    }
    printf("%d\n", (int)ans.size());
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}