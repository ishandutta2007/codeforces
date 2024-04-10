#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N; vector<int> K(N); for(int& x: K) cin >> x;

    int M = *max_element(K.begin(), K.end());

    if(M <= 1)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> C(M+1); for(int x: K) C[x]++;

    // calculate primes
    vector<int> P;
    for(int i=2; i<=M; ++i)
    {
        bool p = true;
        for(int j=2; j*j<=i; ++j) if(i%j == 0) p = false;
        if(p) P.push_back(i);
    }

    vector<vector<int>> fact(M+1, vector<int>(P.size()));
    for(int i=2; i<=M; ++i)
    {
        fact[i] = fact[i-1];
        int ni = i;
        for(int j=0; j<(int)P.size(); ++j)
        {
            while(ni%P[j] == 0)
            {
                ni /= P[j];
                fact[i][j]++;
            }
        }
    }

    // calculate accumulative sum
    for(int i=0; i<=M; ++i)
    {
        for(int j=1; j<(int)P.size(); ++j)
            fact[i][j] += fact[i][j-1];
    }

    auto find_diff = [&](const vector<int>& A, const vector<int>& B)
    {
        // find last nonzero position
        int ia = lower_bound(A.begin(), A.end(), A.back()) - A.begin();
        int ib = lower_bound(B.begin(), B.end(), B.back()) - B.begin();
        if(ia != ib) return max(ia, ib);
        for(int i=ia; i>=0; --i)
        {
            int Av = A[i] - (i > 0 ? A[i-1]: 0);
            int Bv = B[i] - (i > 0 ? B[i-1]: 0);
            if(Av != Bv) return i;
        }
        return -1;
    };

    auto dist = [&](const vector<int>& A, const vector<int>& B)
    {
        int lo = find_diff(A, B);
        if(lo == -1) return 0;

        // lo is first (possibly) different position.
        return (lo > 0 ? A[lo-1] + B[lo-1] : 0) + abs((A[lo]-(lo > 0 ? A[lo-1]: 0))-(B[lo]-(lo > 0 ? B[lo-1]: 0)));
    };

    auto isect = [&](const vector<int>& A, const vector<int> &B)
    {
        int lo = find_diff(A, B);
        if(lo == -1) return A;

        // lo is first (possibly be) different position.
        vector<int> C(A.size());
        C[lo] = min(A[lo]-(lo > 0 ? A[lo-1]: 0), B[lo]-(lo > 0 ? B[lo-1]: 0));
        for(int i=lo+1; i<(int)P.size(); ++i) C[i] = A[i] - A[i-1] + C[i-1];
        return C;
    };


    vector<vector<int>> dis(M+1, vector<int>(M+1));
    for(int i=0; i<=M; ++i) for(int j=0; j<i; ++j)
        dis[i][j] = dis[j][i] = dist(fact[i], fact[j]);



    long long ans = 1e18;

    for(int i=0; i<=M; ++i)
    {
        long long sv = 0;
        for(int j=0; j<=M; ++j)
            sv += 1LL*dis[i][j]*C[j];
        ans = min(ans, sv);
    }
    for(int i=2; i<M; ++i)
    {
        auto v = isect(fact[i], fact[i+1]);
        // for(auto x: v) cout << x << " "; cout << endl;
        long long sv = 0;
        for(int j=0; j<=M; ++j)
            sv += 1LL*dist(v, fact[j])*C[j];
        ans = min(ans, sv);
    }
    cout << ans << endl;
}