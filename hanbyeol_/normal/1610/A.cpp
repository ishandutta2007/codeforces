#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int a, b; cin >> a >> b;
        if(a == 1 && b == 1) cout << 0 << '\n';
        else if(a == 1 || b == 1) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}