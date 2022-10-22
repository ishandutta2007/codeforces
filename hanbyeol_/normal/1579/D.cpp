#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        priority_queue<pair<int, int>> Q;
        for(int i=0; i<N; ++i)
        {
            int t; cin >> t;
            Q.emplace(t, i+1);
        }
        vector<pair<int, int>> ans;
        while(true)
        {
            auto [a, i] = Q.top(); Q.pop();
            auto [b, j] = Q.top(); Q.pop();
            if(b == 0) break;
            ans.emplace_back(i, j);
            Q.emplace(a-1, i); Q.emplace(b-1, j);
        }
        cout << ans.size() << '\n';
        for(auto [a, b]: ans) cout << a << ' ' << b << '\n';
    }
}