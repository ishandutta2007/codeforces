#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

long long n;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        cout << (n * (n + 1) / 2) % 2 << "\n";
}