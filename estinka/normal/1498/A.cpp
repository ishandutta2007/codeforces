#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b)
{
    while (b)
    {
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}
ll sum(ll n)
{
    string s = to_string(n);
    ll val = 0;
    for (char i : s) val += i - '0';
    return val;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        while (gcd(n, sum(n)) == 1) n++;
        cout << n << "\n";
    }
    return 0;
}