#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int N; string s; cin >> N >> s;
        vector<int> V;
        for(int i=0; i<N; ++i) if (s[i] == '2') V.push_back(i);
        if(V.size() == 1 || V.size() == 2)
        {
            cout << "NO\n";
        }
        else
        {
            vector<string> ans(N, string(N, '='));
            for(int i=0; i<N; ++i) ans[i][i] = 'X';
            for(int i=0; i<(int)V.size(); ++i)
            {
                int j = i+1; if(j == (int)V.size()) j = 0;
                ans[V[i]][V[j]] = '-';
                ans[V[j]][V[i]] = '+';
            }
            cout << "YES\n";
            for(auto c: ans) cout << c << '\n';
        }
    }
}