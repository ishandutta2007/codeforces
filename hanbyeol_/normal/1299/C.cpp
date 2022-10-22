#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N; vector<long long> V(N+1);
    for(int i=1; i<=N; ++i)
    {
        cin >> V[i]; V[i] += V[i-1];
    }
    auto ccw = [&](pair<int, long long> a, pair<int, long long> b, pair<int, long long> c)
    {
        auto [ax, ay] = a; auto [bx, by] = b; auto [cx, cy] = c;
        bx -= ax; cx -= ax;
        by -= ay; cy -= ay;
        return bx*cy-cx*by;
    };
    vector<pair<int, long long>> S; S.emplace_back(0, 0LL);
    for(int i=1; i<=N; ++i)
    {
        pair<int, long long> topush = {i, V[i]};
        while(S.size() >= 2)
        {
            auto a = S[S.size()-2];
            auto b = S[S.size()-1];
            auto c = topush;
            if(ccw(a, b, c) > 0) break;
            else S.pop_back();
        }
        S.push_back(topush);
    }
    for(int i=0; i<(int)S.size()-1; ++i)
    {
        auto [ax, ay] = S[i]; auto [bx, by] = S[i+1];
        for(int i=ax; i<bx; ++i)
            cout << fixed << setprecision(12) << (double)(by-ay)/(bx-ax) << '\n';
    }
    return 0;
}