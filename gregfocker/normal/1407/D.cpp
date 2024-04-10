#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rng((long long) (new char));
const int N = (int) 3e5 + 7;
const int INF = (int) 1e9 + 7;
int n;
int a[N];
int dp[N];
int stk[N];
int top;
int p1[N];
int p2[N];
vector<int> ps[N];

void build()
{
    top = 0;
    stk[top] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top && a[stk[top]] <= a[i])
        {
            top--;
        }
        p1[i] = stk[top];
        stk[++top] = i;
    }
    top = 0;
    stk[top] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top && a[stk[top]] >= a[i])
        {
            top--;
        }
        p2[i] = stk[top];
        stk[++top] = i;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build();
    for (int i = 2; i <= n; i++)
    {
        dp[i] = INF;
        int j = i - 1;
        while (j >= 1)
        {
            dp[i] = min(dp[i], dp[j] + 1);
            if (a[j] >= a[i])
            {
                break;
            }
            j = p1[j];
        }
        j = i - 1;
        while (j >= 1)
        {
            dp[i] = min(dp[i], dp[j] + 1);
            if (a[j] <= a[i])
            {
                break;
            }
            j = p2[j];
        }
    }
    cout << dp[n] << "\n";
    return 0;
}