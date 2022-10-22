#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pow2fy(int N)
{
    if(N <= 2) return {};
    int target = 1; while(target < N) target *= 2;
    if(N == target) return pow2fy(N-1);

    vector<pair<int, int>> ret;

    // remove x and target-x
    for(int i=target/2+1; i<=N; ++i)
    {
        ret.emplace_back(target-i, i);
        // target and 2i-target was gotten
        // 2...2N-target remains
    }
    auto fst = pow2fy(target-N-1);
    auto snd = pow2fy(N-target/2);
    for(auto [a, b]: fst) ret.emplace_back(a, b);
    for(auto [a, b]: snd) ret.emplace_back(2*a, 2*b);
    return ret;
}

bool check(int N, vector<pair<int, int>> V)
{
    if((int)V.size() > 20*N) return false;
    int target = 1; while(target < N) target *= 2;
    map<int, int> M;
    for(int i=1; i<=N; ++i) M[i] = 1;
    // cout << N << endl;
    for(auto [a, b]: V)
    {
        // for(auto [a, b]: M) if(b) cout << a << " " << b << endl;
        // cout << endl;
        // cout << "DO" << a << " " << b << endl;
        if(!M[a] || !M[b]) return false;
        if(a == b && M[a] < 2) return false;
        M[a]--; M[b]--;
        M[a+b] += 1; M[abs(a-b)] += 1;
    }
    return M[target] == N;
}

vector<pair<int, int>> solve(int N)
{
    auto ret = pow2fy(N); int target = 1; while(target < N) target *= 2;

    map<int, int> M;
    for(int i=1; i<=N; ++i) M[i] = 1;
    for(auto [a, b]: ret)
    {
        assert(M[a] && M[b]);
        M[a]--; M[b]--;
        M[a+b] += 1; M[abs(a-b)] += 1;
    }
    for(auto &[a, b]: M) assert(b == 0 || ((a&-a) == a));
    bool ok = false; int trm = -1;
    for(auto &[a, b]: M)
    {
        if(b >= 2 && a != target)
        {
            ok = true; trm = a; break;
        }
    }
    assert(ok);
    ret.emplace_back(trm, trm);
    M[trm] -= 2;
    M[2*trm] += 1;
    M[0] += 1;
    for(auto [a, b]: M)
    {
        if(a != 0 && a != target)
        {
            for(int iter=0; iter<b; ++iter)
            {
                int ca = a;
                while(ca != target)
                {
                    // cout << 0 << "!" << ca << endl;
                    ret.emplace_back(0, ca);
                    ret.emplace_back(ca, ca);
                    ca *= 2;
                }
            }
        }
    }
    ret.emplace_back(target, 0);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        if(N == 2)
        {
            cout << -1 << '\n';
        }
        else if(N == 3)
        {
            cout << "3" << '\n';
            cout << "1 3" << '\n';
            cout << "2 2" << '\n';
            cout << "4 0" << '\n';
        }
        else
        {
            // cerr << N << endl;
            auto ans = solve(N);
            cout << ans.size() << '\n';
            for(auto [a, b]: ans) cout << a << " " << b << '\n';
            // assert(check(N, ans));
        }
    }
}