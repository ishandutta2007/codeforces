#include<bits/stdc++.h>

using namespace std;

int N;
vector < int > v[200009];
const int mod = 998244353;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int dfs (int nod, int tata)
{
    int cnt = 1, ans = 1;
    for (auto it : v[nod])
        if (it != tata)
        {
            int curr = dfs (it, nod);
            ans = mul (ans, curr);
            ans = mul (ans, cnt), cnt ++;
        }
    if (tata != -1)
        ans = mul (ans, cnt);
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
printf ("%d\n", mul (N, dfs (1, -1)));
return 0;
}