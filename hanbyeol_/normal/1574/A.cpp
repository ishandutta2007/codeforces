#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        for(int i=0; i<N; ++i)
        {
            //i, N-i
            for(int j=0; j<i; ++j) cout << '(';
            for(int j=0; j<i; ++j) cout << ')';
            for(int j=0; j<N-i; ++j) cout << '(';
            for(int j=0; j<N-i; ++j) cout << ')';
            cout << endl;
        }
    }
}