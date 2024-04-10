#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        vector<int> V(N);
        for(int i=0; i<N; ++i) cin >> V[i];
        cout << (is_sorted(V.begin(), V.end())?"NO":"YES") << '\n';
    }
}