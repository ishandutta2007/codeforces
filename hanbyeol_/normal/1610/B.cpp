#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        vector<int> A(N); for(int&i : A) cin >> i;
        int t1 = -1, t2 = -1;
        for(int i=0; i<N; ++i)
        {
            if(A[i] != A[N-1-i])
            {
                t1 = A[i]; t2 = A[N-1-i];
                break;
            }
        }
        if(t1 == -1){ puts("YES"); continue; }
        vector<int> B, C;
        for(int i=0; i<N; ++i)
        {
            if(A[i] != t1) B.push_back(A[i]);
            if(A[i] != t2) C.push_back(A[i]);
        }
        vector<int> Br(B.rbegin(), B.rend()), Cr(C.rbegin(), C.rend());
        if(B == Br || C == Cr) puts("YES");
        else puts("NO");
    }
}