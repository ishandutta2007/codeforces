#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
string S;
vector <pair <int, int> > v;

vector <int> res;

bool ok (int L, int K, bool fill)
{
    if (L <= 0 || L == 2) return false;
    if (K == 0)
    {
        if (L != 1) return false;
        return true;
    }
    if (K == 1)
    {
        if (L % 2 == 0) return false;
        if (fill)
        {
            for (int i = 0; i < L / 2; i++)
                res.push_back(1);
        }
        return true;
    }
    {
        // K >= 2
        if (fill)
        {
            if (L >= 4 && L % 2 == 0)
            {
                res.push_back(2);
                L -= 3;
            }
            for (int i = 0; i < L / 2; i++)
                res.push_back (1);
        }
        return true;
    }
}

void addon (int L, int K, bool fill)
{
    if (!fill) return;
    res.push_back (L + K);
}

bool works (int K, bool fill)
{
    int s = v[0].first;
    if (!ok (s - (K - 1), K, fill)) return false;
    for (int i = 0; i < v.size(); i++)
    {
        s = v[i].first;
        int e = v[i].second;

        addon (e - s + 1, K, fill);

        if (i + 1 < v.size())
        {
            int s2 = v[i+1].first;
            if (!ok (s2 - e - 1 - K, K, fill)) return false;
        }
    }
    int e = v[v.size() - 1].second;
    if (!ok (N - e - 1 - (K - 1), K, fill)) return false;
    return true;
}

void gogo()
{
    cin >> S;
    N = S.length();
    v.clear();
    res.clear();


    int lo = 0;
    while (lo < N)
    {
        if (S[lo] == '#')
        {
            int hi = lo;
            while (hi + 1 < N && S[hi+1] == '#')
                hi++;
            v.push_back (make_pair (lo, hi));
            lo = hi;
        }
        lo++;
    }

    if (!v.size())
    {
        cout << "0\n\n";
        return;
    }

    M = v.size();
    for (int k = 0; k <= N / M; k++)
    {
        if (works (k, false))
        {
            works (k, true);
            cout << res.size() << "\n";
            for (int i = 0; i < res.size(); i++)
            {
                if (i) cout << " ";
                cout << res[i];
            }
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    int T = 1;
    for (int t = 0; t < T; t++)
        gogo();
}