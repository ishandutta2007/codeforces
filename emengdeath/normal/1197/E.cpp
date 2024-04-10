#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 1e6;
struct node{
    long long sum, extra_v;
    long long ansv;
    node(int SUM = 0, int EXTRA_V = 0){
        sum = SUM;
        extra_v = EXTRA_V;
    };
}f[N],e;
struct node1{
    int in, out;
}a[N];
int n;
void update(node & a, node b) {
    if (a.extra_v > b.extra_v) a = b;
    else
        if (a.extra_v == b.extra_v)
            a.sum = (a.sum + b.sum) % 1000000007;
}
int er(int v) {
    if (a[1].out > v) return -1;
    int l = 1, r = n, mid, s = 0;
    while (l <= r) {
        if (a[mid = (l+r)/ 2].out <= v) l = mid + 1, s =max(s, mid);
        else
            r = mid -1;
    }
    return s;
}
int main() {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n ; i ++)
    {
        scanf("%d %d", &a[i].out, &a[i].in);
        mx = max(mx, a[i].in);
    }
    sort(a + 1, a + n + 1,[](node1 & a, node1 & b) {return a.out < b.out || (a.out == b.out && a.in < b.in);});
    for (int i = 1; i <= n ; i ++)
        if (mx >= a[i].out)
            f[i].extra_v = 1e9;
        else
            f[i].sum = 1, f[i].extra_v = a[i].in;
    e.extra_v = 1e9;
    for (int i = n; i >= 1; i --) {
        if (i != 1) {
            if (a[i].out <= mx)
            update(f[i - 1], node(f[i].sum , f[i].extra_v - a[i].in + a[i].out + a[i - 1].in - a[i - 1].out));
        }
        int x = er(a[i].in);
        if (x != -1)
            update(f[x], node(f[i].sum, f[i].extra_v + a[x].in - a[x].out));
        update(e, f[i]);
    }
    printf("%d\n", e.sum);
    return 0;
}