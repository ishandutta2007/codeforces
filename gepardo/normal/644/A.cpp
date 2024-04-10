#include <iostream>

using namespace std;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    if (a > b * c) cout << -1; else
    {
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int q = (i * c + j) ^ !((i | c) & 1);
                if (q >= a) q = -1;
                cout << q + 1 << " ";
            }
            cout << endl;
        }
    }

}