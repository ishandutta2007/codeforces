#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        string s, t; cin >> s >> t;
        bool p0 = false, p1 = false;
        int ans = 0;
        for(int i=0; i<N; ++i)
        {
            if(s[i] != t[i])
            {
                if(p0) ++ans;
                ans += 2;
                p0 = false; p1 = false;
            }
            else if(s[i] == '0')
            {
                if(!p0) p0 = true;
                else
                {
                    ++ans;
                    p0 = true;
                }
                if(p0 && p1)
                {
                    ans += 2;
                    p0 = false; p1 = false;
                }
            }
            else
            {
                if(p0)
                {
                    ans += 2;
                    p0 = false; p1 = false;
                }
                else
                {
                    p1 = true;
                }
            }
        }
        if(p0) ++ans;
        cout << ans << endl;
    }
}