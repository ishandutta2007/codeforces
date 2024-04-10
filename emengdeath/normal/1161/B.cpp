#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int d[N],  b[N];
int bz[N], has[N];
int ans;
int cnt[N];
struct node{
    int x, y, len;
    void getlen()
    {
        len = min(abs(x - y), n - (abs(x - y)));
    }
}a[N];
bool cmp(const node & a, const node &b)
{
    return a.len < b.len;
}
int did(int x)
{
    x %= n;
    if (!x) return n;
    return x;
}
int gcd(int x, int y)
{
    return !x ? y : gcd(y %x, x);
}
void work(int l, int r)
{
    if (a[l].len * 2==  n)
    {
        for (int j  =1; j <= d[0]; j ++)
            if (d[j] == a[l].len)
                cnt[j] ++;
        return;
    }
    if (l == r) return;
    b[0] = 0;
    for (int i = l ; i <= r;  i ++) {
        if (a[i].y - a[i].x == a[i].len) b[++b[0]] = a[i].x, has[b[b[0]]] = l;
        if (n - (a[i].y - a[i].x) == a[i].len)b[++b[0]] = a[i].y, has[b[b[0]]] = l;
    }
    for (int j = 1; j <= d[0] ; j ++) {
        bool sig = 1;
        for (int i = 1; i <= b[0]; i ++)
            bz[b[i]] = 0;
        for (int i = 1; i <= b[0]; i ++)
            if (!bz[b[i]])
            {

                for (int k = 0; k < n / d[j] && sig; k++)
                    if (has[did((d[j] * k + b[i]))] != l) sig = 0;
                if (sig) {
                    for (int k = 0; k < n / d[j]; k++)
                        bz[did((d[j] * k + b[i]))] = 1;
                } else
                    break;
            }
        if (sig)
            cnt[j] ++;
    }
    return;
}

int main(){
    ans = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; (long long)i * i <= n  ; i++)
        if (n % i == 0)
        {
            d[ ++ d[0]] = i;
            if (i * i != n && i != 1)
                d[++d[0]] = n / i ;
        }
    sort(d + 1, d + d[0] + 1);
    for (int i =  1; i <= m ; i ++)
    {
        scanf("%d %d", &a[i].x ,&a[i].y);
        if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
        a[i].getlen();
    }
    sort(a + 1, a +m + 1, cmp);
    int l = 1;
    int tot_cnt =0;
    for (int i  = 1; i <= m  ; i ++ )
        if (a[i].len != a[l].len) {
            work(l, i - 1);
            l = i;
            tot_cnt ++;
        }
    work(l, m);
    tot_cnt ++;
    for (int i = 1; i <= d[0]; i ++)
        if (cnt[i] == tot_cnt)
        {
            printf("Yes");
            return 0;
        }
    printf("No");
    return 0;
}