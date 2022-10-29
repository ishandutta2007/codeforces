#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int l1[N], r1[N], d1[N], l2[N], r2[N], d2[N], l[N], r[N], d[N], m, tl[N], tr[N], td[N];


void Union(int l1[], int r1[], int d1[], int c1, int l2[], int r2[], int d2[], int c2, int l[], int r[], int d[], int &m){
    m = 0;
    int j = 0;
    for (int i = 0; i < c1; i++){
        while (l1[i] <= r1[i]){
            while (j < c2 && l2[j] > r2[j]) j++;
            if (j >= c2){
                tl[m] = l1[i];
                tr[m] = r1[i];
                td[m++] = d1[i];
                break;
            }
            if (r1[i] <= r2[j]){
                tl[m] = l1[i];
                tr[m] = r1[i];
                td[m++] = d1[i] + d2[j];
                l2[j] = r1[i] + 1;
                l1[i] = r1[i] + 1;
            }else{
                tl[m] = l1[i];
                tr[m] = r2[j];
                td[m++] = d1[i] + d2[j];
                l2[j] = r2[j] + 1;
                l1[i] = r2[j] + 1;
            }
        }
    }
    while (j < c2){
        while (j < c2 && l2[j] > r2[j]) j++;
        tl[m] = l2[j]; tr[m] = r2[j]; td[m++] = d2[j];
        j++;
    }
    int tm = 0;
    for (int i = 0; i < m; i++){
        if (i < m - 1){
            if (td[i] != td[i + 1]){
                l[tm] = tl[i];
                r[tm] = tr[i];
                d[tm++] = td[i];
            }else tl[i + 1] = tl[i];
        }else{
            l[tm] = tl[i];
            r[tm] = tr[i];
            d[tm++] = td[i];
        }
    }
    m = tm;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int n, q;
    scanf("%d%d", &n, &q);
    int m = 1, op, x, y;
    l[0] = 0, r[0] = n - 1, d[0] = 1;
    while (q--){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d", &x);
            for (int i = 0; i < m; i++)
            if (l[i] <= x && r[i] >= x){
                int c1 = 0;
                l1[c1] = 0;
                r1[c1] = x - l[i] - 1;
                d1[c1++] = d[i];
                int now = r1[0] + 1;
                for (int j = i - 1; j >= 0; j--){
                    l1[c1] = now;
                    r1[c1] = now + r[j] - l[j];
                    now = r1[c1] + 1;
                    d1[c1++] = d[j];
                }

                int c2 = 0;
                l2[c2] = 0;
                r2[c2] = r[i] - x;
                d2[c2++] = d[i];
                now = r2[0] + 1;
                for (int j = i + 1; j < m; j++){
                    l2[c2] = now;
                    r2[c2] = now + r[j] - l[j];
                    now = r2[c2] + 1;
                    d2[c2++] = d[j];
                }
                Union(l1, r1, d1, c1, l2, r2, d2, c2, l, r, d, m);
                break;
            }
        }else{
            scanf("%d%d", &x, &y);
            y--;
            int ans = 0;
            for (int i = 0; i < m; i++){
                if (y < l[i] || x > r[i]) continue;
                ans += d[i] * (min(r[i], y) - max(x, l[i]) + 1);
            }
            printf("%d\n", ans);
        }

    }
}