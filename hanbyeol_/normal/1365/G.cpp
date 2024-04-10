#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    const int M = 13, K = 6;
    vector<vector<bool>>V;
    vector<bool> A(K, true); A.resize(M); sort(A.begin(), A.end());
    do
    {
        V.push_back(A);
    } while(next_permutation(A.begin(), A.end()) && (int)V.size() < N);

    vector<uint64_t> QR;

    auto ask = [](vector<int> V)
    {
        if(V.empty()) return (uint64_t)0;
        cout << "? " << V.size();
        for(int x: V) cout << " " << x + 1;
        cout << endl;
        uint64_t v; cin >> v; return v;
    };

    for(int i=0; i<M; ++i)
    {
        vector<int> ta;
        for(int j=0; j<N; ++j)
            if(V[j][i]) ta.push_back(j);
        QR.push_back(ask(ta));
    }

    cout << "!";
    for(int i=0; i<N; ++i)
    {
        uint64_t r = 0;
        for(int j=0; j<M; ++j) if(!V[i][j]) r |= QR[j];
        cout << " " << r;
    }
    cout << endl;
}