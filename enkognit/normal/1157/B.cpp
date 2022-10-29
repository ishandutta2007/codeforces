#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, Q, k, l, T, a[300001], f[1000001];
vector <ll> b;
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 1; i <= 9; i++) cin >> f[i];
    for (int i = 0; i < n; i++)
        if (s[i]-'0'<f[s[i]-'0'])
        {
            for (int j = i; j < n; j++)
            {
                //cout << s[j] << " " << f[s[j]-'0'] << "\n";
                if (s[j]-'0'<=f[s[j]-'0']) s[j]=f[s[j]-'0']+'0'; else break;
            }
            cout << s;
            exit(0);
        }
    cout << s;
}