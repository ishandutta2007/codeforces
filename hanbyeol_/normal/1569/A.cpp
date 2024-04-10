#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int N; string s; cin >> N >> s;
        bool ok = true;
        for(int i=0; i<N-1; ++i)
        {
            if(s[i] != s[i+1])
            {
                cout << i+1 << " " << i+2 << endl;
                ok = false;
                break;
            }
        }
        if(ok) cout << "-1 -1" << endl;
    }
}