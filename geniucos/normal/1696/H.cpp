#include<bits/stdc++.h>

using namespace std;

const int maxN = 609;
int N, k, s[2][maxN], p2[maxN], suf2[maxN][maxN][2], suf[maxN][maxN][2], sumNegativeProducts[maxN][maxN], partialSum[maxN][maxN], partialSumTimesB[maxN][maxN], a[maxN], b[maxN], c[maxN], sg[maxN];
const int mod = 1e9 + 7;
const bool DBG = 0;

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

bool cmp(int x, int y) {
    if (max(x, -x) == max(y, -y))
        return x > y; ///have negatives last
    return max(x, -x) < max(y, -y);
}

int nrb[1 << 15];
long long dp[1 << 15];
int brute(int a[], int K)
{
    function<void(int, string)> printMsk = [&](int msk, string s){
        for (int i=0; i<N; i++)
            if (msk & (1 << i))
                printf("%d", i);
        printf("%s", s.c_str());
    };
    int ans = 0;
    for (int msk = 0; msk < (1 << N); msk ++) {
        nrb[msk] = nrb[msk >> 1] + (msk & 1);
        dp[msk] = -(1LL << 60);
        if (msk > 0)
        {
            if (nrb[msk] == K) {
                dp[msk] = 1LL;
                for (int i=0; i<N; i++)
                    if (msk & (1 << i))
                        dp[msk] = 1LL * dp[msk] * a[i + 1];
            }
            else
            if (nrb[msk] > K) {
                for (int i=0; i<N; i++)
                    if (msk & (1 << i))
                        dp[msk] = max (dp[msk], dp[msk ^ (1 << i)]);
            }
            if (nrb[msk] >= K) {
                int curr = dp[msk] % mod;
                if (curr < 0) curr += mod;
                //printMsk(msk, "->"), printf("%d\n", curr);
                adto(ans, curr);
            }
        }
    }
    return ans;
}

int solve(int a[], int k) {
    int ans = 0;
    p2[0] = 1;
    for (int i=1; i<=N; i++)
        p2[i] = add(p2[i - 1], p2[i - 1]);
    sort (a + 1, a + N + 1);
    for (int i=1; i<=N; i++)
        b[i] = (a[i] < 0 ? a[i] + mod : a[i]);
    ///build standard dps
    ///for the negative case
    int lastNegative = 0;
    while (a[lastNegative + 1] < 0 && lastNegative < N)
        lastNegative ++;
    memset(sumNegativeProducts, 0, sizeof(sumNegativeProducts));
    sumNegativeProducts[lastNegative + 1][0] = 1;
    for (int i=lastNegative; i>=1; i--)
        for (int j=0; j<=lastNegative - i + 1; j++)
        {
            sumNegativeProducts[i][j] = sumNegativeProducts[i + 1][j];
            if (j > 0)
                adto (sumNegativeProducts[i][j], mul(b[i], sumNegativeProducts[i + 1][j - 1]));
        }
    ///consider only sets of size > k
    if (k % 2 == 1)
    {
        ///only case with negative sign is if they're all same sign (if not, one can always change a value in the k-tuple with one outside it)
        ///which means they all must be negative and we choose biggest k; note here by sign we meant < 0 or >= 0
        for (int i=1; i<=lastNegative; i++)
            adto(ans, mul(subtract(p2[i - 1], 1), mul(b[i], sumNegativeProducts[i + 1][k - 1]))); ///first factor is to ensure at least k + 1 elements
        /// consider also the case where there is at least one positive but taking it is a compromise
        memset(sumNegativeProducts, 0, sizeof(sumNegativeProducts));
        sumNegativeProducts[0][0] = 1;
        for (int i=0; i<lastNegative; i++)
            for (int j=0; j<=i; j++)
                adto(sumNegativeProducts[i + 1][j], sumNegativeProducts[i][j]),
                adto(sumNegativeProducts[i + 1][j + 1], mul(sumNegativeProducts[i][j], b[i + 1]));
        for (int i=1; i<=lastNegative; i++)
        {
            int curr = 0;
            vector<int> v;
            for (int j=1; j<=N; j++)
                if (a[j] >= 0 && a[j] <= -a[i]) ///might need strictly smaller here
                    v.push_back(a[j]);
            sort(v.begin(), v.end());
            int cntSoFar = 0;
            for (auto x : v) {
                adto(curr, mul(x, p2[cntSoFar])); ///in how many ways is x the biggest positive?
                cntSoFar ++;
            }
            curr = mul(curr, mul(p2[lastNegative - i], sumNegativeProducts[i - 1][k - 1]));
            adto(ans, curr);
        }
    }

    sort(a + 1, a + N + 1, cmp);
    for (int i=1; i<=N; i++)
        b[i] = (a[i] < 0 ? a[i] + mod : a[i]),
        sg[i] = (a[i] < 0 ? 1 : 0),
        c[i] = (a[i] < 0 ? -a[i] : a[i]);
    /*pref[0][0] = 1;
    for (int i=0; i<N; i++)
        for (int j=0; j<=i; j++)
            adto(pref[i + 1][j], pref[i][j]),
            adto(pref[i + 1][j + 1], mul(pref[i][j], b[i + 1]));*/
    memset(suf, 0, sizeof(suf));
    suf[N + 1][0][0] = 1;
    for (int i=N + 1; i>1; i--)
        for (int j=0; j<=N - i + 1; j++)
            for (int r=0; r<2; r++)
                adto(suf[i - 1][j][r], suf[i][j][r]),
                adto(suf[i - 1][j + 1][r ^ sg[i - 1]], mul(suf[i][j][r], b[i - 1]));
    adto(ans, add(suf[1][k][0], suf[1][k][1])); /// those of size precisely k
    ///add those whose biggest k absolute values happen to yield positive product
    ///this includes when they all are positive
    ///we have considered the case where the largest k have same sign or positive sign overall
    ///so they need to yield negative and we must have at least one of each
    for (int i=1; i<=N; i++)
        adto(ans, mul(subtract(p2[i - 1], 1), mul(b[i], suf[i + 1][k - 1][sg[i]])));
    if (k >= 2) {
        memset(partialSum, 0, sizeof(partialSum));
        memset(partialSumTimesB, 0, sizeof(partialSumTimesB));
        for (int p=1; p<=N; p++) {
            int sameAsP = 0;
            for (int r=p - 1; r>=1; r--)
                if (sg[p] != sg[r]) {
                    partialSum[p][r] = p2[sameAsP + r - 1];
                    partialSumTimesB[p][r] = mul(p2[sameAsP + r - 1], b[r]);
                }
                else sameAsP ++;
            for (int r=1; r<=p; r++)
                adto(partialSum[p][r], partialSum[p][r - 1]),
                adto(partialSumTimesB[p][r], partialSumTimesB[p][r - 1]);
        }

        memset(s, 0, sizeof(s));
        for (int r=0; r<2; r++)
            for (int i=1; i<=N; i++) {
                s[r][i] = s[r][i - 1];
                if (sg[i] == r)
                    adto(s[r][i], b[r]);
            }

        for (int j=N; j>=1; j--) {
            for (int p=0; p<=N - j; p++)
                for (int r=0; r<2; r++)
                    suf2[j][p][r] = suf[j + 1][p][r];
            for (int i=j - 1; i>=1; i--)
                if (sg[i] != sg[j]) {
                    ///let i and j be the last of each sign respectively
                    if (i + 1 + k - 2 <= N && suf2[i + 1][k - 2][0] > 0) {
                        int curr = 0, cntSg[2];
                        cntSg[0] = cntSg[1] = 0;
                        int pntr[2] = {1, 1};
                        for (int p=1; p<i; p++) { ///p is next chosen one by absolute value
                            ///it may be that there's only stuff of his sign left so we need to change it with either i or j depending on its sign
                            if (sg[p] == sg[i]) adto(curr, mul(p2[cntSg[sg[p]]], mul(b[p], b[i])));///drop j, use p instead of j
                            else adto(curr, mul(p2[cntSg[sg[p]]], mul(b[p], b[j]))); ///drop i, use p instead of i
                            ///also the case where

                            if (sg[p] == sg[j]) {
                                while (pntr[0] < p && 1LL * c[pntr[0]] * c[i] < 1LL * c[p] * c[j])
                                    pntr[0] ++;
                                /*int lft = 1, rgt = p - 1, firstTaken = p;
                                ///bestProduct = max(1LL * a[p] * a[j], 1LL * a[r] * a[i]) -- take b[r] * b[i] iff b[r] >= b[p] * b[j] / b[i]
                                while (lft <= rgt) {
                                    int mid = (lft + rgt) >> 1;
                                    if (1LL * c[p] * c[j] <= 1LL * c[mid] * c[i]) firstTaken = mid, rgt = mid - 1;
                                    else lft = mid + 1;
                                }*/
                                int firstTaken = pntr[0];
                                adto(curr, mul(partialSum[p][firstTaken - 1], mul(b[p], b[j])));
                                adto(curr, mul(subtract(partialSumTimesB[p][p], partialSumTimesB[p][firstTaken - 1]), b[i]));
                            } else {
                                while (pntr[1] < p && 1LL * c[pntr[1]] * c[j] < 1LL * c[p] * c[i])
                                    pntr[1] ++;
                                /*int lft = 1, rgt = p - 1, firstTaken = p;
                                ///bestProduct = max(1LL * a[p] * a[i], 1LL * a[r] * a[j]) -- take b[r] * b[j] iff b[r] >= b[p] * b[i] / b[j]
                                while (lft <= rgt) {
                                    int mid = (lft + rgt) >> 1;
                                    if (1LL * c[p] * c[i] <= 1LL * c[mid] * c[j]) firstTaken = mid, rgt = mid - 1;
                                    else lft = mid + 1;
                                }*/
                                int firstTaken = pntr[1];
                                adto(curr, mul(partialSum[p][firstTaken - 1], mul(b[p], b[i])));
                                adto(curr, mul(subtract(partialSumTimesB[p][p], partialSumTimesB[p][firstTaken - 1]), b[j]));
                            }

                            /*int sameAsP = 0;
                            for (int r=p - 1; r>=1; r--)
                                if (sg[p] != sg[r]) {
                                    long long bestProduct;
                                    if (sg[p] == sg[j])
                                        bestProduct = max(1LL * a[p] * a[j], 1LL * a[r] * a[i]);
                                    else
                                        bestProduct = max(1LL * a[p] * a[i], 1LL * a[r] * a[j]);
                                    adto(curr, mul(p2[sameAsP + r - 1], bestProduct % mod));
                                }
                                else sameAsP ++;*/
                            cntSg[sg[p]] ++;
                        }
                        curr = mul (curr, suf2[i + 1][k - 2][0]);
                        adto(ans, curr);
                    }

                    ///maybe take this in the knapsack
                    for (int p=0; p<=N - i; p++)
                        for (int r=0; r<2; r++)
                            suf2[i][p][r] = suf2[i + 1][p][r];
                    for (int p=0; p<=N - i; p++)
                        for (int r=0; r<2; r++)
                            adto(suf2[i][p + 1][r ^ sg[i]], mul(suf2[i + 1][p][r], b[i]));
                } else {
                    for (int p=0; p<=N - i; p++)
                        for (int r=0; r<2; r++)
                            suf2[i][p][r] = suf2[i + 1][p][r];
                }
        }
    }
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

srand(time(0));
int tests = 1;
if (DBG)
    scanf("%d", &tests);
while (tests --) {
    if (!DBG) {
        scanf ("%d %d", &N, &k);
        for (int i=1; i<=N; i++)
            scanf ("%d", &a[i]);
        int ans = solve(a, k);
        printf("%d\n", ans);
        /*{
            int actual = brute(a, k);
            if (actual != ans) printf ("WA %d instead of %d\n", ans, actual);
            else printf ("OK %d\n", ans);
        }*/
    }
    else {
        N = 4, k = 3;
        for (int i=1; i<=N; i++)
            a[i] = rand () % 10 - 5;
        printf("[");
        for (int i=1; i<=N; i++)
            printf("%d%c", a[i], ",]"[i == N]);
        printf("->");
        int cor = brute(a, k), given = solve(a, k);
        if (cor != given) {
            printf ("WA %d instead of %d\n", given, cor);
            return 0;
        }
        else printf("%d\n", cor);
    }
}
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/