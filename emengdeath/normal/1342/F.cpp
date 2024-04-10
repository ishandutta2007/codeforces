#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 15;
int n, T;
int a[N];
vector<pair<int, int> > ans;
vector<int> A, B;
int sig;
int nowid[N];
struct node{
    int mn, from;
    int bz;
    void update(int mn_, int from_) {
        if (bz != sig || mn_ < mn)
            mn = mn_, from = from_, bz = sig;
    }
}f[1<<N][N + 1];
int h[1<<N];
void check() {
    if (A.size() == 0 || A.size() <= ans.size()) return;
    sig ++;
    f[0][0].mn = 0;
    f[0][0].bz = sig;
    for (int i = 0; i < B.size(); i ++)
        h[1 << i] = a[B[i]];
    for (int i = 1; i < (1 << B.size()); i ++)
        h[i] = h[i - (i&-i)] + h[i&-i];
    for (int i = 0; i < A.size(); i ++)
        for (int j = 0; j < (1 << B.size()); j ++)
            if (f[j][i].bz == sig) {
                int tmp = (1 << B.size()) - j - 1;
                for (int k = tmp; k ; k = ((k -1) & tmp))
                    if (h[k] + a[A[i]]> f[j][i].mn)
                        f[j + k][i + 1].update(h[k] + a[A[i]], j);
                if (a[A[i]] > f[j][i].mn)
                    f[j][i + 1].update(a[A[i]], j);
            }
    int tmp = (1 <<B.size()) - 1;
    if (f[tmp][A.size()].bz == sig){
        ans.resize(0);
        for (int i = A.size(); i > 0; i --) {
            int v = 0;
            int w = tmp - f[tmp][i].from;
            for (int j = 0; j < B.size(); j++)
                if ((w >> j) & 1)
                    v |= (1 << B[j]);
            ans.push_back({A[i - 1], v});
            tmp = f[tmp][i].from;
        }
    }
}
void dfs(int x) {
    if (x == n) {
        check();
        return;
    }
    A.push_back(x);
    dfs(x + 1);
    A.pop_back();
    B.push_back(x);
    dfs(x + 1);
    B.pop_back();
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        ans.clear();
        dfs(0);

        printf("%d\n", n - ans.size());
        for (int i = 0; i < n; i ++)
            nowid[i] = i + 1;
        for (auto u:ans)
            for (int i = 0; i < n; i ++)
                if ((u.second >> i) & 1) {
                    printf("%d %d\n", nowid[i], nowid[u.first]);
                    for (int j = i; j < n; j ++)
                        nowid[j] --;
                }
    }
    return 0;
}