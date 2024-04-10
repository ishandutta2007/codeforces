#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N; cin >> N;
        vector<int> A(N), B(N);
        for(int&a:A) cin >> a;
        for(int&b:B) cin >> b;
        vector<int> cnt(N+1);
        int p1 = 0, p2 = 0;
        while(p1 != N && p2 != N)
        {
            if(A[p1] == B[p2])
            {
                if(cnt[A[p1]]) --cnt[A[p1]];
                else ++p1;
                ++p2;
            }
            else
            {
                ++cnt[A[p1]];
                ++p1;
            }
        }
        if(p1 == N && p2 == N) puts("YES");
        else puts("NO");
    }
}