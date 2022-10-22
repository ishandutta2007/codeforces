#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, S; cin >> N >> S;
    if(S >= 2*N)
    {
        cout << "YES" << endl;
        for(int i=0; i<N-1; ++i) cout << 2 << " ";
        cout << S - (2*(N-1)) << endl;
        cout << 1 << endl;
    }
    else cout << "NO" << endl;
}