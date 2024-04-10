#include<bits/stdc++.h>

using namespace std;

const int maxN = 509, maxM = 1000009;
int N, M, a[maxM], l[maxN], r[maxN];
const int mod = 998244353;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

/*int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}*/

void finish0() {
    printf("0\n");
    exit(0);
}

int compute(vector<pair<int, int>> &v);
int solve(int i, int j) {
    if (r[a[i]] == j) {
        int curr = 1;
        for (int k=i; k<=j; k++)
            if (a[k] != a[i]) {
                int p = k;
                while (p < j && a[p + 1] != a[i])
                    p ++;
                curr = mul(curr, solve(k, p));
                k = p;
            }
        for (int k=i; k<=j; k++)
            if (a[k] < a[i])
                finish0();
        return curr;
    }
    vector<pair<int, int>> v;
    int k = i;
    while (k <= j) {
        if (r[a[k]] > j || k != l[a[k]])
            finish0();
        v.push_back({a[k], solve(k, r[a[k]])}),
        k = r[a[k]] + 1;
    }
    return compute(v);
}

int cnt[maxN][maxN];
int compute(vector<pair<int, int>> &v) {
    int nr = v.size();
    assert(nr >= 2);
    for (int i=1; i<=nr + 1; i++)
        cnt[i][i - 1] = 1;
    for (int i=nr; i>=1; i--) {
        cnt[i][i] = v[i - 1].second;
        int minPos = i;
        for (int j=i + 1; j<=nr; j++) {
            if (v[j - 1].first < v[minPos - 1].first)
                minPos = j;
            cnt[i][j] = 0;
            int firstHalf = 0, secondHalf = 0;
            for (int k=i; k<=minPos; k++)
                adto(firstHalf, mul(cnt[i][k - 1], cnt[k][minPos - 1]));
            for (int k=minPos; k<=j; k++)
                adto(secondHalf, mul(cnt[minPos + 1][k], cnt[k + 1][j]));
            cnt[i][j] = mul(cnt[minPos][minPos], mul(firstHalf, secondHalf));
        }
    }
    return cnt[1][nr];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    scanf("%d", &a[i]), r[a[i]] = i, l[a[i]] = (l[a[i]] == 0 ? i : l[a[i]]);
printf("%d\n", solve(1, M));
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/