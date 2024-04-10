#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

int n, m, i, a[3000001], b[3000001], ans[3000001];
string s;
vector <ll> v, z;

int main()
{
    //freopen("words.in","r",stdin);
    //freopen("words.out","w",stdout);
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) v.pb(a[i+1]-a[i]);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n-1; i++) z.pb(b[i+1]-b[i]);
    sort(v.begin(),v.end());
    sort(z.begin(),z.end());
    for (int i = 0; i < v.size(); i++)
    {
        //cout << v[i] << " " << z[i] << "\n";
        if (v[i]!=z[i]) {cout << "No\n";exit(0);}
    }
    if (a[0]!=b[0])cout << "No\n"; else
    cout << "Yes\n";
    return 0;
}