#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct tnode{
    long long s, sign;
} t[800005];
int n, m, i;
long long w, h, ans, a[100005];
void build(int x, int l, int r){
    t[x].sign = 0;
    if (l == r){
        t[x].s = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(x + x, l, mid);
    build(x + x + 1, mid + 1, r);
    t[x].s = max(t[x + x].s, t[x + x + 1].s);
}
void down(int x){
    if (t[x].sign){
        t[x + x].sign = t[x].sign;
        t[x + x + 1].sign = t[x].sign;
        t[x].s = t[x].sign;
        t[x].sign = 0;
    }
}
void query(int x, int l, int r, int a, int b){
    down(x);
    if (a > r || b < l) return;
    if (l >= a && r <= b){
        ans = max(ans, t[x].s);
        return;
    }
    int mid = (l + r) / 2;
    query(x + x, l, mid, a, b);
    query(x + x + 1, mid + 1, r, a, b);
    t[x].s = max(t[x + x].s, t[x + x + 1].s);
}
void insert(int x, int l, int r, int a, int b, long long c){
    down(x);
    if (a > r || b < l) return;
    if (l >= a && r <= b){
        t[x].sign = c;
        down(x);
        return;
    }
    int mid = (l + r) / 2;
    insert(x + x, l, mid, a, b, c);
    insert(x + x + 1, mid + 1, r, a, b, c);
    t[x].s = max(t[x + x].s, t[x + x + 1].s);
}
int main(){
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cin >> m;
    for (i = 1; i <= m; i++){
        cin >> w >> h;
        ans = 0;
        query(1, 1, n, 1, w);
        cout << ans << endl;
        insert(1, 1, n, 1, w, h + ans);
    }
}