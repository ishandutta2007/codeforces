#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
class ODT{
public:
    struct node {
        int l, r;
        mutable long long v;

        node(int L, int R = -1, long long V = 0) : l(L), r(R), v(V) {}

        bool operator<(const node &o) const {
            return l < o.l;
        }
        int len() const{
            return r - l + 1;
        }
    };
    set<node>s;
    void init_array(vector<int>a) {
        int i = 0;
        for (auto u:a)
        {
            i ++;
            s.insert(node(i, i, u));
        }
        ++i;
        s.insert(node(i, i, 0));
    }
#define IT set<node>::iterator
    IT split(int pos) {
        IT it = s.lower_bound(node(pos));
        if (it != s.end() && it->l == pos) return it;
        --it;
        int L = it->l, R = it->r;
        long long V = it->v;
        s.erase(it);
        s.insert(node(L, pos - 1, V));
        return s.insert(node(pos, R, V)).first;
    }
    void assign(int l, int r, long long val = 0) {
        IT itl = split(l), itr = split(r + 1);
        s.erase(itl, itr);
        s.insert(node(l, r, val));
    }
    void add(int l ,int r, long long val = 0) {
        IT itl = split(l), itr = split(r + 1);
        while (itl != itr) itl->v += val, itl ++;
    }
    long long power(long long x, long long y, long long mod) {
        x %= mod;
        long long z = 1;
        while (y) {
            if (y & 1) (z *= x) %= mod;
            (x *= x) %= mod, y /= 2;
        }
        return z;
    }
    long long sum_of_xth_power_mod_y(int l, int r, int x, int y) {
        IT itl = split(l), itr = split(r + 1);
        long long ans = 0;
        while (itl != itr) ans = (ans + power(itl->v, x, y) * itl->len()) % y, itl ++;
        return ans;
    }
    long long search_x_smallest(int l, int r, int x) {
        IT itl = split(l), itr = split(r + 1);
        vector<pair<long long, int> > d;
        while (itl != itr) d.push_back(make_pair(itl->v, itl->len())), itl ++;
        sort(d.begin(), d.end());
        for (auto u:d)
            if (u.second >= x)
                return u.first;
            else
                x -= u.second;
        return -1;
    }
}odt;
int seed, n, m, vmx;
int rnd(){
    int ret = seed;
    seed = ((long long)seed * 7 + 13) % 1000000007;
    return ret;
}
int main() {
    scanf("%d %d %d %d", &n, &m, &seed, &vmx);
    vector<int>a;
    for (int i = 1; i <= n ; i ++) {
        int x = rnd() % vmx + 1;
        a.push_back(x);
    }
    odt.init_array(a);
    while (m -- ){
        int op = rnd() % 4 + 1;
        int l = rnd() % n + 1;
        int r = rnd() % n + 1;
        if  (l > r) swap(l, r);
        int x, y;
        if (op == 3) {
            x = (rnd() % ( r - l  + 1)) + 1;
        } else
            x = (rnd() % vmx) + 1;
        if (op == 4)
            y = (rnd() % vmx) + 1;

        switch (op){
            case 1:
            odt.add(l, r, x);
            break;
            case 2:
            odt.assign(l, r, x);
            break;
            case 3:
            printf("%lld\n", odt.search_x_smallest(l, r, x));
            break;
            case 4:
            printf("%lld\n", odt.sum_of_xth_power_mod_y(l, r, x, y));
            break;
        }
    }
    return 0;
}