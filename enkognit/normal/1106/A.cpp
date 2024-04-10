#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>

using namespace std;

ll n, m, i, j, k, l, r, ans;
string s[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 1; i < n-1; i++)
        for (int j = 1; j < n-1; j++)
            if (s[i][j]=='X' && s[i-1][j-1]=='X' && s[i+1][j-1]=='X' && s[i-1][j+1]=='X'
                && s[i+1][j+1]=='X') ans++;
    cout << ans;
    return 0;
}
/*
7 2
1 1 1 1 1 3 3
1 2 3 3 1 1
*/