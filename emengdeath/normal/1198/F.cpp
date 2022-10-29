#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
namespace two_prime_groups_division{//1e9
    const int K = 9;
    const int N = 1e5 + 1;
    int bz[N];//
    int bz1[N];//
    bool g[1 << (2 * (K + 1))];
    int b[K * 10], id[K * 10];
    int tag[N];
    vector<int>p[N];//
    unordered_map<int, pair<int, int> > f; //2
    unordered_map<int, bool> havedone;//
    void attend(int x, int y) {
        if (f[x].first) {
            if (f[x].first != y)f[x] = make_pair(f[x].first, y);
        }else
            f[x] = make_pair(y, 0);
    }
    inline int lowbit(int x){
        return x & -x;
    }
    int * work1(int * a, int n) {//n<=2*k
        for (int i = 0; i <= n ; i ++)
            bz1[i] = 0;
        g[0] = 0;
        for (int i = 1; i < (1 << n); i ++) {
            int y = lowbit(i);
            int x = a[__builtin_ctz(y) + 1];
            int z = i;
            while (z -= y) {
                y = lowbit(z);
                x = __gcd(a[__builtin_ctz(y) + 1], x);
            }
            g[i] = (x == 1);
        }
        for (int i = 1; i < (1 << n) ; i += 2)
            if (g[i] && g[(1 << n) - i - 1]) {
                bz1[0] = 1;
                for (int j = 1; j <= n; j ++)
                    if (i & (1 << (j - 1)))
                        bz1[j] = 1;
                break;
            }
        return bz1;
    }
    vector<int> divide(int x) {
        vector<int> p;
        p.clear();
        for (int j = 2; (long long)j * j <= x; j ++ )
            if (x % j == 0) {
                p.push_back(j);
                while (x % j== 0) x /= j;
            }
        if (x != 1)
            p.push_back(x);
        return p;
    }
    void choose_killer(vector<int>&g, int sig, int * a, int& n) {
        for (auto u:g)
            for (int i = 1; i <= n ; i ++)
                if (tag[i] != sig && a[i] % u) {
                    tag[i] = sig;
                    id[++id[0]] = i;
                    break;
                }
    }
    int * work(int *a, int n) {
        for (int i = 0; i <= n ; i ++)
            bz[i] = 0, tag[i] = 0;
        if (n <= 2*(K + 1))
            return work1(a, n);
        for (int i = 2; i <= K + 2; i ++) {
            if (havedone[a[i]])continue;
            havedone[a[i]] = 1;
            id[0] = 2, id[1] = 1, id[2] = i;
            tag[1] = tag[i] = i;
            vector<int> p1 = divide(a[i]);
            vector<int> p2 = divide(a[1]);
            choose_killer(p1, i, a, n);
            choose_killer(p2, i, a, n);
            for (int j = 1; j <= id[0];j ++)
                b[j] = a[id[j]];
            int * c = work1(b, id[0]);
            if (c[0] == 1) {
                for (int j = 1; j <= id[0]; j ++)
                    bz[id[j]] = c[j];
                bz[0] = 1;
                return bz;
            }
        }
        return bz;
    }
    /*
    void choose_killer(int x, int sig) {
        for (auto u:p[x]) {
            pair<int, int>v = f[u];
            if (v.first &&  tag[v.first] != sig) {
                id[++id[0]] = v.first;
                tag[v.first] = sig;
                continue;
            }
            if (v.second &&  tag[v.second] != sig) {
                id[++id[0]] = v.second;
                tag[v.second] = sig;
                continue;
            }
        }
    }
     int * work(int * a, int n) {//1,00 n 
        for (int i = 0; i <= n ; i ++)
            bz[i] = 0, tag[i] = 0;
        if (n <= 2*(K + 1))
            return work1(a, n);
        for (int i = 1; i <= n; i ++) {
            int x = a[i];
            for (int j = 2; (long long)j * j <= x; j ++ )
                if (x % j == 0) {
                    p[i].push_back(j);
                    while (x % j== 0) x /= j;
                }
            if (x != 1)
                p[i].push_back(x);
            for (auto u:p[i]) {
                if (i != 1 && a[i - 1] % u)
                    attend(u, i - 1);
                if (i != n && a[i + 1] % u)
                    attend(u, i + 1);
            }
        }
        for (int i = 2; i <= K + 2; i ++) {
            if (havedone[a[i]])continue;
            havedone[a[i]] = 1;
            id[0] = 2, id[1] = 1, id[2] = i;
            tag[1] = tag[i] = i;
            choose_killer(i, i);
            choose_killer(1, i);
            for (int j = 1; j <= id[0];j ++)
                b[j] = a[id[j]];
            int * c = work1(b, id[0]);
            if (c[0] == 1) {
                for (int j = 1; j <= id[0]; j ++)
                    bz[id[j]] = c[j];
                bz[0] = 1;
                return bz;
            }
        }
        havedone.clear();
        f.clear();
        for (int i = 1; i <= n ; i ++)
            p[i].clear();
        return bz;
    }*/
}
const int N = 1e5 + 1;
int a[N];
int n;
int main(){
  //  freopen("input", "r" ,stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    int *b = two_prime_groups_division::work(a, n);
    if (!b[0]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 1; i <= n ; i++)
        printf("%d%c", b[i] + 1, " \n"[i == n]);
    return 0;
}