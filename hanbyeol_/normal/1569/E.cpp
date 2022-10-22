#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

map<int, vector<int> > G(vector<int> iv, vector<int> V, vector<int> raw)
{
    map<int, vector<int>>ret;
    for(int i=0; i<1<<((int)iv.size()-1); ++i)
    {
        int ni = i;
        vector<int> cur = {0};
        for(int j=1; j<(int)V.size(); ++j)
        {
            vector<int> n;
            for(int x: cur)
            {
                if(ni&1) n.push_back(x), n.push_back(j);
                else n.push_back(j), n.push_back(x);
                ni >>= 1;
            }
            cur = n;
        }
        int ans = 0;
        vector<int> r(iv.size());
        for(int i=0; i<(int)iv.size(); ++i)
            ans = (1LL*iv[i]*V[cur[i]]+ans)%MOD, r[i] = raw[cur[i]];
        ret[ans] = r;

    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int K, A, H; cin >> K >> A >> H;

    vector<int> V(K), Vr(K); V[0] = A, Vr[0] = 1;
    for(int i=1; i<K; ++i) V[i] = 1LL*V[i-1]*V[i-1]%MOD, Vr[i] = 2*Vr[i-1];
    for(int&x: Vr) ++x;
    for(int&x : V) x = 1LL*x*A%MOD;

    vector<int> U = V, Ur = Vr; U[0] = A; Ur[0] = 1;
    vector<int> X(1<<(K-1)), Y(1<<(K-1));
    iota(X.begin(), X.end(), 1);
    iota(Y.begin(), Y.end(), 1+(1<<(K-1)));

    for(int i=0; i<2; ++i){
        auto M1 = G(X, U, Ur); auto M2 = G(Y, V, Vr);

        for(const auto&[a, b]: M1)
        {
            int targ = H-a; if(targ < 0) targ += MOD;
            auto it = M2.find(targ);
            if(it != M2.end())
            {
                for(auto x: b) cout << x << " ";
                for(auto x: it->second) cout << x << " ";
                cout << endl;
                return 0;
            }
        }
        swap(U, V);
        swap(Ur, Vr);
    }
    cout << -1 << endl;
}