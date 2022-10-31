#include <bits/stdc++.h>
#define MN 100100

using namespace std;

int n, v[MN], l[MN], r[MN], pai[MN], rut;
map<int, int> freq;

int suc(int no, int L, int R) {
    if(no == -1) return 0;

    int ret = suc(l[no], L, min(R, v[no] - 1));
    ret += suc(r[no], max(L, v[no] + 1), R);
    if(L <= v[no] && v[no] <= R) ret += freq[v[no]];
    return ret;
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", &v[i], &l[i], &r[i]);
        pai[l[i]] = i;
        pai[r[i]] = i;
        freq[v[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        if(pai[i] == 0) rut = i;
    }

    printf("%d\n", n - suc(rut, INT_MIN, INT_MAX));
    return 0;
}