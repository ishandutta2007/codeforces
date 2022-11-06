#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t, a, b;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        ll c = abs(a - b) + 9;
        c /= 10;
        cout << c << "\n";
    }
}