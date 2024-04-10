#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N; vector<int> V(N);
        vector<int> cnt(N+1);
        set<int> S; for(int i=0; i<=N; ++i) S.insert(i);
        for(int&x: V)
        {
            cin >> x; cnt[x]++;
            S.erase(x);
        }
        int mex = *S.begin();

        set<int> pushed;
        vector<int> ans;
        for(int x: V)
        {
            if(x < mex) pushed.insert(x);
            if(--cnt[x] == 0) S.insert(x);
            if((int)pushed.size() == mex)
            {
                ans.push_back(mex);
                mex = *S.begin();
                pushed.clear();
            }
        }
        cout << ans.size() << endl;
        for(int x: ans) cout << x << " ";
        cout << endl;
    }
}