#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N; cin >> N;
        vector<int> V(N); for(int&x:V) cin >> x;
        int ma = -1, mi = N;
        for(int i=0; i<N-1; i++)
            if(V[i] == V[i+1])
            {
                ma = max(ma, i);
                mi = min(mi, i);
            }
        if(ma == -1) cout << 0 << endl;
        else if(ma==mi) cout << 0 << endl;
        else if(ma-mi == 1) cout << 1 << endl;
        else cout << ma-mi-1 << endl;
    }
}