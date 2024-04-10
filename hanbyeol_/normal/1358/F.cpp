#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<long long> A(N), B(N);
    for(auto&x: A) cin >> x;
    for(auto&x: B) cin >> x;

    vector<long long> RA(A.rbegin(), A.rend());

    if(N == 1)
    {
        if(A == B) cout << "SMALL" << endl << 0 << endl << endl;
        else cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    const int LIM = 200000;
    string ans = "";
    long long cnt = 0;
    auto ar = [&](){ if(cnt<=LIM) ans += 'R'; };
    auto ap = [&](long long p){
        cnt += p; if(cnt <= LIM) for(int i=0; i<p; ++i) ans += 'P';
    };
    while(A != B && RA != B)
    {
        bool is_incr = true, is_decr = true;
        for(int i=0; i<N-1; ++i)
        {
            if(B[i] <= B[i+1]) is_decr = false;
            if(B[i] >= B[i+1]) is_incr = false;
        }
        if(is_decr)
        {
            ar();
            reverse(B.begin(), B.end());
        }
        if(is_incr || is_decr)
        {
            if(N == 2)
            {
                if(A[0] == B[0])
                {
                    long long delta = B[1] - A[1];
                    if(delta > 0 && delta%B[0] == 0)
                    {
                        ap(delta/B[0]);
                        B[1] -= delta;
                    }
                    else break;
                }
                else if(RA[0] == B[0])
                {
                    long long delta = B[1] - RA[1];
                    if(delta > 0 && delta%B[0] == 0)
                    {
                        ap(delta/B[0]);
                        B[1] -= delta;
                    }
                    else break;
                }
                else
                {
                    long long maxop = (B[1]-1)/B[0];
                    ap(maxop);
                    B[1] -= maxop*B[0];
                }
            }
            else
            {
                for(int i=N-1; i>0; --i) B[i] -= B[i-1];
                ap(1);
            }
        }
        else break;
    }
    if(RA == B)
    {
        reverse(B.begin(), B.end()); ar();
    }
    if(A != B) cout << "IMPOSSIBLE" << endl;
    else if(cnt > 200000) cout << "BIG" << endl << cnt << endl;
    else cout << "SMALL" << endl << ans.size() << endl << string(ans.rbegin(), ans.rend()) << endl;
}