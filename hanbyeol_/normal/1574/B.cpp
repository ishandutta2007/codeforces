#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int a, b, c, m; cin >>a>>b>>c>>m;
        if(2*max({a,b,c})-(a+b+c+1) <= m && m <= a+b+c-3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}