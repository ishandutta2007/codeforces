#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int N, M, K; cin >> N >> M >> K;
        vector<string> A(N), B(N, string(M, '.'));
        for(auto&s: A) cin >> s;
        for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
        {
            int d;
            for(d=0;;++d)
            {
                if(i-d < 0 || j-d < 0 || j+d >= M) break;
                if(A[i-d][j-d] == '.' || A[i-d][j+d] == '.') break;
            }
            if(d-1 >= K)
                for(int v=0; v<d; ++v)
                    B[i-v][j-v] = B[i-v][j+v] = '*';
        }
        cout << (A == B ? "YES" : "NO") << endl;
    }
}