#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int n, k;
long long Ans[200005], D[200005], G[200005], R[200005], C[200005];

struct seg
{
    long long L, R;
    long long val;
};
bool operator<(seg x, seg y)
{
    return x.R != y.R ? x.R < y.R : x.L < y.L;
}
set<seg> st;

void modify(seg x)
{
    // printf("modifying [%lld,%lld,%lld]\n", x.L, x.R, x.val);
    auto It = st.upper_bound({-1, x.L, 0});
    while (It != st.end() && It->L <= x.R)
    {
        auto tmpIt = It;
        auto cur = *It;
        It++;
        st.erase(tmpIt);
        if (cur.L < x.L)
            st.insert({cur.L, x.L - 1, cur.val});
        if (cur.R > x.R)
            st.insert({x.R + 1, cur.R, cur.val});
    }
    st.insert(x);
}
long long query(long long x)
{
    // printf("querying %lld\n", x);
    auto It = st.upper_bound({-1, x, 0});
    if (It == st.end() || It->L > x)
        return -1;
    // printf("result = %lld\n", It->val);
    return It->val;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &R[i], &C[i]);
        G[i] = (G[i] - C[i] + k) % k;
        R[i] = (R[i] - C[i] + k) % k;
        // printf("state : [%d,%d)\n", G[i], R[i]);
    }
    for (int i = 2; i <= n; i++)
    {
        long long x;
        scanf("%lld", &x);
        D[i] = D[i - 1] + x;
    }
    for (int i = n; i >= 1; i--)
    {
        long long Ti = ((G[i] - D[i]) % k + k) % k;
        long long nxt = query(Ti);
        if (nxt == -1)
            Ans[i] = D[n] - D[i];
        else
        {
            Ans[i] = D[nxt] - D[i] + Ans[nxt];
            long long tmpTi = (G[i] + D[nxt] - D[i]) % k;
            Ans[i] += (G[nxt] - tmpTi + k) % k;
        }
        // printf("Ans[%d] = %lld\n", i, Ans[i]);
        long long modL = ((R[i] - D[i]) % k + k) % k, modR = ((G[i] - 1 - D[i]) % k + k) % k;
        if (modL <= modR)
            modify({modL, modR, i});
        else
            modify({modL, k - 1, i}), modify({0, modR, i});
    }
    long long sum = 0, ans = 1e16;
    for (auto &p : st)
    {
        // printf("{%lld,%lld,%lld}\n", p.L, p.R, p.val);
        sum += p.R - p.L + 1;
        ans = min(ans, D[p.val] + Ans[p.val] + (G[p.val] - (D[p.val] + p.R) % k + k) % k);
    }
    if (sum != k)
        ans = D[n];
    printf("%lld\n", ans);
}