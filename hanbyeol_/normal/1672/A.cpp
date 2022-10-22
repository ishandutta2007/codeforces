#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int a = 0;
        while (N--)
        {
            int t;
            cin >> t;
            a += t - 1;
        }
        a %= 2;

        cout << (a ? "errorgorn" : "maomao90") << endl;
    }
}