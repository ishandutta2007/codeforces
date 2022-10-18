#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n, x, a, b, c, ans;

int main()
{
    cin>>n>>a>>b;
    while (n--) {
        cin >> x;
        if (x == 1) {
            if (a > 0)
                --a;
            else if (b > 0)
                --b, ++c;
            else if (c > 0)
                --c;
            else
                ++ans;
        } else {
            if (b > 0)
                --b;
            else
                ans += 2;
        }
    }
    cout<<ans;
}