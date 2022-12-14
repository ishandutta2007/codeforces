#include<bits/stdc++.h>
#define MN 200000
#define lll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='1') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

/* 
Key idea: check whether the starting point in in all possible maximum matchings
*/

int n, m;
int a[MN + 5], b[MN + 5], aa, bb, rr, cc, Left[MN + 5], holes[MN + 5]; 

lll solve(int v, int R, int C) {
    lll res = 0;
    for (int i = 1; i <= m; ++i) Left[i] = holes[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int t = upper_bound(b + 1, b + m + 1, v - a[i]) - b;
        int needed = m + 1 - t, has = t - 1;
        if (R == i) {
            if (C < t) -- has;
            else -- needed;
        }
        if (has > needed) {
            res += needed;
            Left[t] -= 1;
            Left[t - (has - needed)] += 1;
            if (R == i && C < t && C >= t - (has - needed)) {
                Left[C] -= 1;
                Left[C + 1] += 1;
                Left[t - (has - needed)] -= 1;
                Left[t - (has - needed) - 1] += 1;
            }
        } else {
            res += has;
            holes[t] += 1;
            holes[t + (needed - has)] -= 1;
            if (R == i && C >= t && C < t + (needed - has)) {
                holes[C] -= 1;
                holes[C + 1] += 1;
                holes[t + (needed - has)] += 1;
                holes[t + (needed - has) + 1] -= 1;
            }
        }
    }
    lll ll = 0;
    for (int i = 1; i <= m; ++i) {
        holes[i] += holes[i - 1];
        Left[i] += Left[i - 1];
        lll x = min(holes[i], Left[i]);
        res += x;
        if (Left[i] > x) {
            lll y = min(ll, Left[i] - x);
            res += y;
            ll -= y;
        } else {
            ll += holes[i] - x;   
        }
    }
    return res;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i) b[i] = read();
    aa = a[1]; bb = b[1];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == aa) {
            rr = i;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (b[i] == bb) {
            cc = i;
            break;
        }
    }
    int l = 1, r = aa + bb - 1, mid, res = aa + bb;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (solve(mid, rr, cc) != solve(mid, 0, 0)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", res);
    return 0;
}