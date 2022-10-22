#include<bits/stdc++.h>
using namespace std;

bool can(int K, vector<pair<int, int>> V)
{
    int cur = 0;
    for(auto [ri, po]: V)
        if(ri >= K-cur-1 && po >= cur) ++cur;
    return cur >= K;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N; vector<pair<int, int>> V(N);
        for(auto&[a, b]: V) cin >> a >> b;
        int lo = 0; // pos
        int hi = N+1; // impos
        while(lo+1!=hi)
        {
            int mi = (lo+hi)/2;
            if(can(mi, V)) lo = mi;
            else hi = mi;
        }
        cout << lo << '\n';
    }
}