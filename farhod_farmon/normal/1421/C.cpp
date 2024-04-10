#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        string s;
        cin >> s;
        int n = s.size();
        cout << 3 << "\n";
        cout << "L " << n - 1 << "\n";
        cout << "R " << n - 1 << "\n";
        cout << "R " << 2 * n - 1 << "\n";
}