#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N; string s; cin >> s;
        int ans = 0;
        for(int i=0; i<N; ++i)
        {
            ans += s[i] -'0';
            if(i != N-1 && s[i] != '0') ++ans;
        }
        cout << ans << endl;
    }
}