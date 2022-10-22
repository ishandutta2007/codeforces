#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N; vector<vector<int> > conn(N); vector<int> deg(N);
        using Q = priority_queue<int, vector<int>, greater<int>>;
        Q c, n;
        for(int i=0; i<N; ++i)
        {
            int K; cin >> K;
            for(int j=0; j<K; ++j)
            {
                int x; cin >> x; --x;
                conn[x].push_back(i);
                ++deg[i];
            }
            if(deg[i] == 0) c.push(i);
        }
        int ans = 0;
        while(!c.empty())
        {
            ++ans;
            while(!c.empty())
            {
                int x = c.top(); c.pop();
                for(int v: conn[x])
                {
                    // cout << x << "->" << v << endl;
                    if(--deg[v] == 0)
                    {
                        if(x < v) c.push(v);
                        else n.push(v);
                    }
                }
            }
            c.swap(n);
        }
        if(*max_element(deg.begin(), deg.end()) == 0) cout << ans << endl;
        else cout << -1 <<endl;
    }
}