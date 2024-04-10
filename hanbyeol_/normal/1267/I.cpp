#include<bits/stdc++.h>
using namespace std;

void solve(int N)
{
    vector<int> perm(2*N); iota(perm.begin(), perm.end(), 1);
    auto comp = [&](int a, int b)
    {
        if(a == b) return false;
        cout << "? " << perm[a] << " " << perm[b] << endl;
        char c; cin >> c; return c == '<';
    };
    vector<int> A = {0, 1}; vector<int> B(N-2); iota(B.begin(), B.end(), 2);
    for(int i=N; i<2*N; ++i)
    {
        if(A.size() > B.size()) B.push_back(i); else A.push_back(i);
        auto am = min_element(A.begin(), A.end(), comp);
        auto bm = min_element(B.begin(), B.end(), comp);
        if(comp(*am, *bm)) A.erase(am); else B.erase(bm);
    }
    cout << "!" << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N; solve(N);
    }
}