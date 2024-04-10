#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> perm;
void init(int n)
{
    perm.resize(n); iota(perm.begin(), perm.end(), 0);
    shuffle(perm.begin(), perm.end(), rng);
}

int cnt = 0;
int ask(int a, int b)
{
    // ++cnt;
    // return perm[a] | perm[b];
    cout << "? " << perm[a]+1 << " " << perm[b]+1 << endl;
    int t; cin >> t; return t;
}

void ans(vector<int> V)
{
    // assert(V == perm);
    // cout << cnt << endl;
    // exit(0);
    cout << "!";
    vector<int> pr(V.size());
    for(int i=0; i<(int)V.size(); ++i) pr[perm[i]] = V[i];
    for(int x: pr) cout << " " << x;
    cout << endl;
    exit(0);
}

int main()
{
    int N; cin >> N; init(N);
    vector<tuple<int, int, int>> V;
    uniform_int_distribution<int> dis(0, N-1);
    vector<pair<int, int>> invest;
    while(invest.empty())
    {
        int a, b;
        do
        {
            a = dis(rng);
            b = dis(rng);
        } while(a == b);
        V.emplace_back(a, b, ask(a, b));
        for(int i=0; invest.empty() && i<(int)V.size()-1; ++i)
            for(int j=0; invest.empty() && j<i; ++j)
            {
                int k = (int)V.size()-1;
                auto [a1, b1, v1] = V[i];
                auto [a2, b2, v2] = V[j];
                auto [a3, b3, v3] = V[k];
                if((v1&v2&v3) == 0)
                {
                    invest.emplace_back(a1, v1);
                    invest.emplace_back(a2, v2);
                    invest.emplace_back(a3, v3);
                }
            }
    }
    vector<int> ret;
    for(int i=0; i<N; ++i)
    {
        int ans = 2047;
        for(auto [a, b]: invest)
        {
            if(i == a) ans &= b;
            else ans &= ask(i, a);
        }
        ret.push_back(ans);
        if(ans == 0)
        {
            invest.clear();
            invest.emplace_back(i, 0);
        }
        if(invest.size() == 3)
        {
            for(int i=0; i<(int)ret.size()-1; ++i)
                if((ret[i] & ret.back()) == 0)
                {
                    invest.clear();
                    invest.emplace_back(i, ret[i]);
                    invest.emplace_back((int)ret.size()-1, ret.back());
                }
        }
    }
    ans(ret);
}