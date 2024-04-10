#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
queue <int> q;
int to[N], from[N], a[N], q1[N], n, v[N];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        to[i] = i + 1;
        from[i] = i - 1;
    }

    for (int i = 1; i < n; i++) if (a[i] > a[i + 1]) q.push(i + 1);
    a[n + 1] = n + 1;
    int ans = 0;
    while (!q.empty()){
        int cnt = 0;
        while (!q.empty()){
            int t = q.front(); q.pop();
            v[t] = 1;
            q1[++cnt] = t;
        }
        for (int i = 1; i <= cnt; i++){
            int t = q1[i];
            int l = from[t];
            int r = to[t];
            to[l] = r;
            from[r] = l;
            if (!v[l] && !v[r] && a[l] > a[r]) q.push(r);
        }
        ans++;
    }
    cout << ans << endl;
}