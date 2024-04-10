#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;

int n,ans;
string s1,s2;

int main()
{
    cin>>n>>s1>>s2;
    for (int i = 0; i < n; ++i) {
        int d1 = s1[i] - 48;
        int d2 = s2[i] - 48;
        ans += min(abs(d1-d2), min(abs(10+d1-d2), abs(10-d1+d2)));
    }
    cout << ans;

    return 0;
}