#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll k, x;
    cin >> n >> k >> x;
    vector<ll> a(n), v;
    for (int i =0; i < n; i++) 
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i =1; i < n; i++) 
    {
        v.push_back(max(0ll, (a[i] - a[i-1]-1)/x));
    }
    sort(v.begin(), v.end());
    ll gr = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (k >= v[i])
        {
            k -= v[i];
        }
        else 
        {
            gr = n - i;
            break;
        }
    }
    cout << gr << "\n";
    return 0;
}