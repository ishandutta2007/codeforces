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
            int a; cin >> a;
            int b = 1;
            while(b*2 < a) b *= 2;
            cout << b << " ";
        }
        cout << endl;
    }
}