#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e4 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;



PI p[N];
int t[N];


int main(){
    int n;
    char ch;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf(" %c%d", &ch, &p[i].second);
        p[i].second--;
        if (ch == 'R') p[i].first = 0;
        if (ch == 'G') p[i].first = 1;
        if (ch == 'B') p[i].first = 2;
        if (ch == 'Y') p[i].first = 3;
        if (ch == 'W') p[i].first = 4;
    }

    sort(p, p + n);
    n = unique(p, p + n) - p;

    int ans = INF;

    for (int i = 0; i < 1 << 5; i++)
    for (int j = 0; j < 1 << 5; j++){
        int cnt = 0;
        for (int k = 0; k < 5; k++){
            if (i >> k & 1) cnt++;
            if (j >> k & 1) cnt++;
        }
        memset(t, 0, sizeof(t));
        for (int k = 0; k < n; k++)
        if (i >> p[k].first & 1) t[k] += 1 << p[k].first;
        for (int k = 0; k < n; k++)
        if (j >> p[k].second & 1) t[k] += 1 << p[k].second + 5;

        int flag = 0;
        sort(t, t + n);
        for (int k = 1; k < n; k++)
        if (t[k] == t[k - 1]) flag = 1;
        if (!flag) ans = min(ans, cnt);
    }

    cout << ans << endl;

}