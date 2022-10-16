#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

void re(int& x);
void re(long long& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

long long last = 0;
int qs;
int cnt = 1;

long long w[410000];
int seq[410000][23];
long long sum[410000][23];

void solve()
{
    for (int j = 19; j >= 0; j--) {
        seq[0][j] = -1;
        sum[0][j] = 0;
    }

    for (re(qs); qs; qs--) {
        int op; long long p,q;
        re(op,p,q); p ^= last; q ^= last;
        p--;

        //dbg(op,p,q);
        if (op == 1) {
            w[cnt] = q;
            if (w[p] >= w[cnt]) {
                seq[cnt][0] = p;
                sum[cnt][0] = w[p];
            }
            else {
                int cur = p;
                for (int j = 19; j >= 0; j--) {
                    if (seq[cur][j] != -1 && w[seq[cur][j]] < w[cnt]) cur = seq[cur][j];
                }
                seq[cnt][0] = seq[cur][0];
                sum[cnt][0] = (seq[cnt][0] == -1) ? 0 : w[seq[cnt][0]];
                // dbg(cnt,seq[cnt][0],sum[cnt][0]);
            }
            
            for (int j = 1; j < 20; j++) {
                if (seq[cnt][j-1] == -1) {
                    seq[cnt][j] = -1;
                    sum[cnt][j] = sum[cnt][j-1];
                }
                else {
                    seq[cnt][j] = seq[seq[cnt][j-1]][j-1];
                    sum[cnt][j] = sum[cnt][j-1] + sum[seq[cnt][j-1]][j-1];
                }
            }

            cnt++;
        }

        else {
            if (w[p] > q) {
                last = 0;
                ps(last);
                continue;
            }

            last = 1;
            q -= w[p];
            for (int j = 19; j >= 0; j--) {
                // dbg(p,q,seq[p][j],sum[p][j]);
                if (seq[p][j] != -1 && sum[p][j] <= q) {
                    // dbg("take",j,q,seq[p][j],sum[p][j]);
                    q -= sum[p][j];
                    p = seq[p][j];
                    
                    last += (1<<j);
                }
            }
            ps(last);
        }
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }
void re(long long& x) { scanf("%lld", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}