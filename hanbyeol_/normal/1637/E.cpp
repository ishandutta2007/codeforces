#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N, M; cin >> N >> M;
        vector<int> V(N); for(int&x: V) cin >> x;
        vector<pair<int, int>> ban(M); for(auto&[a, b]: ban) cin >> a >> b;
        sort(ban.begin(), ban.end());
        sort(V.begin(), V.end());
        int v = V[0], c = 1;
        map<int, vector<int>> MM;
        for(int i=1; i<N; ++i)
        {
            if(v == V[i]) ++c;
            else
            {
                MM[c].push_back(v);
                v = V[i], c = 1;
            }
        }
        MM[c].push_back(v);
        vector<pair<int, vector<int>>> targ(MM.begin(), MM.end());
        for(int i=0; i<(int)targ.size(); ++i)
            sort(targ[i].second.rbegin(), targ[i].second.rend());
        long long ans = 0;
        for(int i=0; i<(int)targ.size(); ++i)
        {
            for(int j=0; j<=i; ++j)
            {
                int small = i, large = j;
                if(targ[i].second.size() > targ[j].second.size()) swap(small, large);

                int sumcnt = targ[i].first + targ[j].first;

                for(int k: targ[small].second)
                    for(int s: targ[large].second)
                    {
                        if(k == s) continue;
                        if(binary_search(ban.begin(), ban.end(), make_pair(min(k, s), max(k, s)))) continue;
                        ans = max(ans, 1LL*sumcnt*(k+s));
                        break;
                    }
            }
        }
        cout << ans << '\n';
    }
}