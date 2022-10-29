#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
const int N = 5e5 + 10;
int q;
struct node1{
    int v, sig, id;
}Q[N];
pair<int, int> c[N];
struct node{
    long long tag, mx_b_2a;
    int sum;
}f[N * 4];
map<int, vector<int>> w;
void upd(int s) {
    f[s].sum = f[s+s].sum + f[s+s+1].sum;
    f[s].mx_b_2a = max(f[s+s].mx_b_2a, f[s+s+1].mx_b_2a);
}
void down(int l, int r, int s) {
    if (f[s].tag) {
        f[s].mx_b_2a += f[s].tag;
        if (l!=r) f[s+s].tag += f[s].tag, f[s+s+1].tag += f[s].tag;
        f[s].tag = 0;
    }
}
void ins(int l, int r, int s, pair<int, int> u, int sig) {
    down(l, r, s);
    if (c[l] > u || c[r] < u) return;
    if (l == r) {
        if (sig) {
            f[s].sum = 1;
            f[s].mx_b_2a += u.first;
        } else {
            f[s].sum = 0;
            f[s].mx_b_2a -= u.first;
        }
        return;
    }
    ins(l, (l+r) / 2, s + s, u, sig);
    ins((l+r ) /2 + 1, r, s + s+ 1, u, sig);
    upd(s);
}
void add(int l, int r, int s, pair<int, int> u, int sig) {
    down(l, r, s);
    if (c[r] <= u) return;
    if (c[l] > u) {
        if (sig)
            f[s].tag -= u.first * 2;
        else
            f[s].tag += u.first * 2;
        down(l, r, s);
        return;
    }
    add(l, (l+r)/ 2, s+s, u, sig);
    add((l+r) / 2 + 1, r, s + s + 1, u ,sig);
    upd(s);
}
int get(int l, int r, int s) {
    down(l, r, s);
    if (f[s].mx_b_2a <= 0 || !f[s].sum) return 0;
    if (l == r) return 1;
    return get(l,(l+r)/2,s+s) + get((l+r)/2+1,r,s+s+1);
}
int main() {
    scanf("%d", &q);
    for (int i = 1; i  <= q; i ++) {
        char x;
        scanf(" %c %d", &x, &Q[i].v);
        if (Q[i].sig = (x == '+')) w[Q[i].v].push_back(i), Q[i].id = i, c[i] = {Q[i].v, i};
        else {
            auto u = w.find(Q[i].v);
            Q[i].id =  u->second.at(u->second.size() - 1);
            c[i] = {Q[i].v, i};
            u->second.pop_back();
        }
    }
    sort(c + 1, c + q + 1);
    for (int i = 1; i <= q; i ++) {
        switch(Q[i].sig) {
            case 1:
                ins(1, q, 1, {Q[i].v, Q[i].id}, 1);
                add(1, q, 1, {Q[i].v, Q[i].id}, 1);
                break;
            case 0:
                ins(1, q, 1, {Q[i].v, Q[i].id}, 0);
                add(1, q, 1, {Q[i].v, Q[i].id}, 0);
                break;
        }
        printf("%d\n", f[1].sum - get(1, q, 1));
    }
    return 0;
}