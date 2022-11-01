#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 210;
const int maxk = 1100;
const int mod = 1e9 + 7;

int n, k;

vector <int> svi;

int x;

int bio[maxn][maxn][maxk];

int add(int a, int b)
{
    a += b;
    if(a >= mod) a -= mod;
    if (a < 0) a += mod;
    return a;
}

int mult(int a, int b)
{
    return (long long) a * b % mod;
}

int rek(int ind, int otv, int sum)
{
    if(bio[ind][otv][sum] != -1) return bio[ind][otv][sum];
    if(ind >= n)
    {
        if(otv) return bio[ind][otv][sum] = 0;
        if(sum <= k) return bio[ind][otv][sum] = 1;
        else return bio[ind][otv][sum] = 0;
    }
    if(sum > k)
    {
        return bio[ind][otv][sum] = 0;
    }
    if(ind == n - 1 && otv > 1) return bio[ind][otv][sum] = 0;
    int raz;
    if(ind == n - 1) raz = 0;
    else raz = svi[ind + 1] - svi[ind];
    int ret = 0;
    if(sum + otv * raz <= k) ret = add(ret, rek(ind + 1, otv, sum + otv * raz));
    if(sum + otv * raz + raz <= k) ret = add(ret, rek(ind + 1, otv + 1, sum + otv * raz + raz));
    if(otv)
    {
        if(sum + otv * raz <= k) ret = add(ret, mult(otv, rek(ind + 1, otv, sum + otv * raz)));
        if(sum + (otv - 1) * raz <= k) ret = add(ret, mult(otv, rek(ind + 1, otv - 1, sum + (otv - 1) * raz)));
    }
    //cout << ind << " " << otv << " " << sum << " " << ret << endl;
    return bio[ind][otv][sum] = ret;
}

int main()
{
    memset(bio, -1, sizeof bio);
    scanf("%d%d", &n, &k);
    REP(i, 0, n)
    {
        scanf("%d", &x);
        svi.push_back(x);
    }
    sort(svi.begin(), svi.end());
    printf("%d\n", rek(0, 0, 0));
    return 0;
}