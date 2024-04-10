#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;
const long long mod = 1e9 + 7;

using namespace std;


int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        //freopen("nodes.in","r",stdin);
        ios_base::sync_with_stdio(0);

        int n, k;
        cin >> n >> k;
        int a = n * 2, b = n * 5, c = n * 8;
        a = (a - 1) / k + 1;
        b = (b - 1) / k + 1;
        c = (c - 1) / k + 1;
        cout << a + b + c << "\n";
}