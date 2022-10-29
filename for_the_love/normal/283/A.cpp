#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct Tnode{
    long long sign, s;
} t[1000020];
int n, p, a, b, cnt;

void down(int x, int l, int r){
    t[x + x].sign += t[x].sign;
    t[x + x + 1].sign += t[x].sign;
    t[x].s += (r - l + 1) * t[x].sign;
    t[x].sign = 0;
}
long long Getsum(int x, int l, int r, int a, int b){
    if (t[x].sign) down(x, l, r);
    if (l >= a && r <= b) return t[x].s;
    int mid = (l + r) / 2; long long ret = 0;
    if (a <= mid) ret += Getsum(x + x, l, mid, a, b);
    if (b > mid) ret += Getsum(x + x + 1, mid + 1, r, a, b);
    if (t[x + x].sign) down(x + x, l, mid);
    if (t[x + x + 1].sign) down(x + x + 1, mid + 1, r);
    t[x].s = t[x + x].s + t[x + x + 1].s;
    return ret;
}
void add(int x, int l, int r, int a, int b, long long delta){
    if (t[x].sign) down(x, l, r);
    if (l >= a && r <= b){
        t[x].sign = delta;
        down(x, l, r);
        return;
    }
    int mid = (l + r) / 2;
    if (a <= mid) add(x + x, l, mid, a, b, delta);
    if (b > mid) add(x + x + 1, mid + 1, r, a, b, delta);
    if (t[x + x].sign) down(x + x, l, mid);
    if (t[x + x + 1].sign) down(x + x + 1, mid + 1, r);
    t[x].s = t[x + x].s + t[x + x + 1].s;
}
void insert(int x, int l, int r, int a, int b){
    if (t[x].sign) down(x, l, r);
    if (l == a && r == a){
        t[x].s = b;
        return;
    }
    int mid = (l + r) / 2;
    if (a <= mid) insert(x + x, l, mid, a, b);
    else insert(x + x + 1, mid + 1, r, a, b);
    if (t[x + x].sign) down(x + x, l, mid);
    if (t[x + x + 1].sign) down(x + x + 1, mid + 1, r);
    t[x].s = t[x + x].s + t[x + x + 1].s;
}
int main(){
    scanf("%d", &n);
    n++; cnt = 1;
    for (int i = 1; i < n; i++){
        scanf("%d", &p);
        if (p == 1){
            cin >> b >> a;
            add(1, 1, n, 1, min(cnt, b), a);
        }else if (p == 2){
            cin >> a;
            cnt++;
            insert(1, 1, n, cnt, a);
        }else if (p == 3){
            if (cnt > 1){
                insert(1, 1, n, cnt, 0);
                cnt--;
            }
        }
        printf("%lf\n", Getsum(1, 1, n, 1, cnt) / (double)cnt);
    }
}