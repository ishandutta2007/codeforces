#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
const int M = 1e6 + 100;
int f[M];
const int mod = 1e9 + 7;
namespace border_pam {//pam borderdpborderborderlog,diffanc pamborder
    struct node {
        int son[26];
        int fail, len;
        int diff,  anc;//borderborderfaillog
        int g;//logxborderlendx-dlen-dborderdpupdate
        void clear() {
            for (int i = 0; i < 26; i++)
                son[i] = 0;
            fail = len = 0;
            diff = anc = 0;
        }
    } tri[M];

    char S[M];
    int lst, L, N, len;

    void pre() {
        S[0] = -1;
        tri[1].clear();
        tri[0].clear();
        tri[1].len = -1;
        tri[0].fail = 1;
        lst = 0;
        L = 1;
    }

    int getfail(int x) {
        while (S[N] != S[N - tri[x].len - 1])x = tri[x].fail;
        return x;
    }

    void add() {
        static int y;
        y = getfail(lst);
        if (!tri[y].son[S[N] - 'a']) {
            tri[++L].clear();
            tri[L].fail = tri[getfail(tri[y].fail)].son[S[N] - 'a'], tri[L].len = tri[y].len + 2;
            tri[y].son[S[N] - 'a'] = L;
            tri[L].diff = tri[L].len - tri[tri[L].fail].len;
            tri[L].anc = (tri[tri[L].fail].diff == tri[L].diff)?tri[tri[L].fail].anc:tri[L].fail;
        }
        lst = tri[y].son[S[N] - 'a'];
    }
    void update(int x){
        for (int i = lst; i > 1; i = tri[i].anc) {
            tri[i].g = f[x - tri[tri[i].anc].len - tri[i].diff];
            if (tri[i].anc != tri[i].fail)
                (tri[i].g += tri[tri[i].fail].g ) %= mod;
            (f[x] += ((x & 1) == 0) * tri[i].g ) %= mod;
        }
    }
}
int n;
char t[M];
int main() {
    scanf("%s", t + 1);
    n = strlen(t + 1);
    int x = 0;
    for (int i = 1; i <= n / 2; i ++) {
        border_pam::S[++x] = t[i];
        border_pam::S[++x] = t[n - i + 1];
    }
    border_pam::pre();
    f[0] = 1;
    for (border_pam::N = 1; border_pam::N <= n;border_pam:: N ++){
        border_pam::add();
        border_pam::update(border_pam::N);
    }
    printf("%d\n", f[n]);
    return 0;
}