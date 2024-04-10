#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
const int N = 20;
int f[N][1<<N], tmp[1<<N],g[1<<N];
long long all[1<<N], allx[1 << N];
int n;
long long a[N];
int help[1 << N];
namespace FWT
{
    void FWT_or(int *a,int N,int opt)
    {
        for(int i=1;i<N;i<<=1)
            for(int p=i<<1,j=0;j<N;j+=p)
                for(int k=0;k<i;++k)
                    if(opt==1)a[i+j+k]=a[j+k]+a[i+j+k];
                    else a[i+j+k]=a[i+j+k] -a[j+k];
    }
}
namespace FST{
    const int N = 20;
    int A[N + 1][1 << N], B[N + 1][1 << N], C[N + 1][1 << N];
    void gao(int * a, int *b, int *c, int n, bool a_b_the_same = false) {
        for (int i = 0;i <= n ; i++)
            for (int j = 0; j < (1 << n); j ++)
                A[i][j] = B[i][j] = C[i][j] = 0;
        for (int i = 0; i < (1 << n); i ++) {
            A[__builtin_popcount(i)][i] = a[i];
            if (!a_b_the_same)
                B[__builtin_popcount(i)][i] = b[i];
        }
        for (int i = 0; i <= n; i ++) {
            FWT::FWT_or(A[i], 1 << n, 1);
            if (!a_b_the_same)
                FWT::FWT_or(B[i], 1 << n, 1);
            else {
                for (int j = 0; j < (1 << n); j ++)
                    B[i][j] = A[i][j];
            }
        }
        for (int i = 0; i <= n ; i ++)
            for (int j = 0; j + i <= n; j ++)
                for (int k = 0; k < (1 << n); k ++)
                    C[i + j][k] += A[i][k] * B[j][k];
        for (int i = 0; i <= n; i ++) {
            FWT::FWT_or(C[i], 1 << n, 0);
        }
        for (int j = 0; j < (1 << n) ; j ++)
            c[j] = C[__builtin_popcount(j)][j];
    }
}
inline long long myabs(long long x) {
    return x < 0 ? -x : x;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%lld", &a[i]), help[1<<i] = i;
    for (int i = 0; i < n; i ++)
        if (!a[i]) {
            swap(a[i], a[n - 1]);
            n --;
            i --;
        }
    for (int i = 1; i < (1 << n); i ++)
        all[i] = all[i - (i & (-i))] + a[help[i & (-i)]];
    for (int i = 2; i < (1 << n) ; i ++)
        if (!help[i]) {
            int tmp = i;
            vector<int>d;
            while (tmp) {
                d.push_back(tmp & (-tmp));
                tmp -= (tmp & -tmp);
            }
            long long v = all[i];
            int sum = d.size();
            vector<long long> A((1<<(sum/2)) - 1), B((1<<((sum+1) / 2)) - 1);
            for (int j = 1; j < (1<< (sum / 2)); j ++) {
                allx[j] = allx[j - (j & -j)] + all[d[help[j & -j]]] * 2;
                if (-sum<v - allx[j] && v - allx[j] < sum && ((v - allx[j] - sum) & 1)) {
                    f[0][i] = 1;
                    break;
                }
                A[j - 1] = allx[j];
            }
            if (f[0][i]) continue;
            for (int j = 1; j < (1 << ((sum + 1) / 2)); j ++) {
                allx[j] = allx[j - (j & -j)] + all[d[help[j & -j] + sum / 2]] * 2;
                if (-sum<v - allx[j] && v - allx[j] < sum && ((v - allx[j] - sum) & 1)) {
                    f[0][i] = 1;
                    break;
                }
                B[j - 1] = v - allx[j];
            }
            if (f[0][i]) continue;
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());
            int la = 0, lb = 0;
            while ((la + 1 < A.size())|| (lb + 1 < B.size())) {
                if (la + 1 == A.size()) {
                    ++lb;
                    if (myabs(A[la] - B[lb]) < sum && ((A[la] - B[lb] - sum) & 1)) {
                        f[0][i] = 1;
                        break;
                    }
                } else
                if (lb + 1 == B.size()) {
                    la ++;
                    if (myabs(A[la] - B[lb]) < sum && ((A[la] - B[lb] - sum) & 1)) {
                        f[0][i] = 1;
                        break;
                    }
                } else {
                    if ((myabs(A[la + 1] - B[lb]) < sum && ((A[la +1] - B[lb] - sum) & 1)) ||(myabs(A[la] - B[lb + 1]) < sum &&((A[la] - B[lb + 1] - sum) & 1))) {
                        f[0][i] = 1;
                        break;
                    }
                    if (A[la + 1] < B[lb + 1])
                        la ++;
                    else
                        lb ++;
                }
            }
        }
    int mx = 0;
    for (int i = 1; (1 << i) <= n; i ++) {
        FST::gao(f[i - 1], f[i - 1], f[i], n, 1);
        bool sig = 0;
        for (int j = 0; j < (1 << n); j ++)
            sig |= (f[i][j] = (f[i][j] > 0));
        if (!sig) break;
        mx = i;
    }
    int ans = 0;
    g[0] = 1;
    for (int i = mx; i >= 0; i --) {
        FST::gao(f[i], g, tmp, n);
        bool sig = 0;
        for (int j = 0; j < (1 << n); j ++)
            if (tmp[j]) {
                sig = 1;
                break;
            }
        if (!sig) continue;
        for (int j = 0; j < (1 << n); j ++)
            g[j] = (tmp[j] > 0);
        ans += (1 << i);
    }
    printf("%d\n", n - ans);
    return 0;
}