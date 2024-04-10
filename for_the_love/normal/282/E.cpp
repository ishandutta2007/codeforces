#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, i, cnt, rt, c[4000020][2], next[4000020][2];
long long sum, a[100005], p[100005], q[41], ans;
void Insert(long long x){
    int i, rt = 0, b[41];
    for (i = 40; i >= 1; i--){
        b[i] = x % 2;
        x = x / 2;
    }
    for (i = 1; i <= 40; i++){
        c[rt][b[i]]++;
        if (c[rt][b[i]] == 1) rt = next[rt][b[i]] = ++cnt; else rt = next[rt][b[i]];
    }
}
void Del(long long x){
    int i, rt = 0, b[41];
    for (i = 40; i >= 1; i--){
        b[i] = x % 2;
        x = x / 2;
    }
    for (i = 1; i <= 40; i++){
        c[rt][b[i]]--;
        rt = next[rt][b[i]];
    }
}
long long Getmax(long long x){
    int i, b[41], rt = 0;
    long long ret = 0, tmp, t = x;
    for (i = 40; i >= 1; i--){
        b[i] = x % 2;
        x = x / 2;
    }
    x = t;
    for (i = 1; i <= 40; i++){
        tmp = q[40 - i];
        if (!c[rt][0] && c[rt][1]){
            rt = next[rt][1];
            ret += (x ^ tmp) & tmp;
        }else if (!c[rt][1] && c[rt][0]){
            rt = next[rt][0];
            ret += x & tmp;
        }else if (x & tmp){
            rt = next[rt][0];
            ret += tmp;
        }else{
            rt = next[rt][1];
            ret += tmp;
        }
    }
    return ret;
}
int main(){
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    sum = 0;
    for (i = 0; i <= n; i++){
        p[i] = p[i - 1] ^ a[i];
        Insert(p[i]);
    }
    q[0] = 1;
    for (i = 1; i <= 40; i++) q[i] = q[i - 1] * 2;
    ans = Getmax(0);
    for (i = n; i >= 1; i--){
        if (i <= n) Del(p[i]);
        sum = sum ^ a[i];
        ans = max(ans, Getmax(sum));
    }
    cout << ans << endl;
}