#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T; scanf("%d", &T); while(T--)
    {
        int N; scanf("%d", &N);
        vector<int> A(N); for(int&x: A) cin >> x;
        vector<int> cnt(N+1);
        vector<vector<int>> ord(N);
        for(int i=0; i<N; i++)
        {
            int v = A[i];
            ord[cnt[v]].push_back(i);
            cnt[v]++;
        }
        vector<int> B(N);
        for(int i=0; i<N; i++)
        {
            sort(ord[i].begin(), ord[i].end(), [&](int x, int y)
            {
                if(cnt[A[x]] != cnt[A[y]]) return cnt[A[x]] < cnt[A[y]];
                return A[x] < A[y];
            });
            for(int j=0; j<(int)ord[i].size(); j++)
            {
                int f = ord[i][j];
                int n = ord[i][(j+1)%ord[i].size()];
                B[f] = A[n];
            }
        }
        for(int x: B) cout << x << " ";
        cout << endl;
    }
}