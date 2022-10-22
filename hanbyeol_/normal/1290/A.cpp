#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N, M, K; cin >> N >> M >> K; K = min(K, M-1);
        vector<int> V(N); for(int&x: V) cin >> x;
        vector<int> U(M); for(int i=0; i<M; ++i) U[i] = max(V[i], V[i+(N-M)]);
        int ans = 0;
        for(int i=0; i<=K; ++i) ans = max(ans, *min_element(U.begin()+i, U.begin()+i+(M-K)));
        cout << ans << endl;
    }
}