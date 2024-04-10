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

ll n, m, i, j, Q, k, l, T, a[300001];
string s;
vector <ll> v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    ll p=(n-11)/2, w=p;
    for (int i = 0; i < n; i++)
        if (s[i]=='8' && s.size()-i>=11)
        {
            if (p) p--; else
            {
                cout << "YES\n";
                exit(0);
            }
        }else if (w)w--; else break;
    cout << "NO\n";
}
/*
10 11
1 2
1 3
1 4
3 4
2 5
2 6
5 6
3 7
4 8
5 9
6 10
*/