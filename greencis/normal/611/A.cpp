#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n;
int m[12] = {31,29,31,30, 31,30,31,31, 30,31,30,31};
int d[7] = {52,52,52,52,53,53,52};
string s1,s2;

int main()
{
    cin >> n >> s1 >> s2;
    if (s2 == "month") {
        int ans = 0;
        for (int i = 0; i < 12; ++i)
            ans += (n <= m[i]);
        cout << ans;
    } else {
        cout << d[n-1];
    }

    return 0;
}