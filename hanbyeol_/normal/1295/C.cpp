#include <bits/stdc++.h>
using namespace std;

int solve(string S, string T)
{
    vector<vector<int>> nxt(S.size());
    nxt.back().resize(26, -1);
    nxt.back()[S.back()-'a'] = (int)S.size()-1;
    for(int i=(int)S.size()-2; i>=0; --i)
    {
        nxt[i] = nxt[i+1];
        nxt[i][S[i]-'a'] = i;
    }
    int ans = 1, cur = 0;
    for(auto c: T)
    {
        if(cur == (int)S.size())
        {
            cur = 0;
            ++ans;
        }
        if(nxt[0][c-'a'] == -1) return -1;
        cur = nxt[cur][c-'a'] + 1;
        if(cur == 0)
        {
            ++ans;
            cur = nxt[cur][c-'a'] + 1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        string S, T; cin >> S >> T;
        cout << solve(S, T) << endl;
    }
}