#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, M;
        cin >> n >> M;
        auto inp = [M](int N)
        {
            // rmn, cnt
            vector<pair<int, long long>> res;
            for (int i = 0; i < N; i++)
            {
                int X;
                cin >> X;
                long long c = 1;
                while (X % M == 0)
                {
                    X /= M;
                    c *= M;
                }
                if (!res.empty() && res.back().first == X)
                    res.back().second += c;
                else
                    res.emplace_back(X, c);
            }
            return res;
        };
        auto A = inp(n);
        int K;
        cin >> K;
        auto B = inp(K);
        if (A == B)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}