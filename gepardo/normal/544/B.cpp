#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int k; cin >> k;
    int mv = (n * n + 1) / 2;
    if (k > mv) { cout << "NO"; return 0; }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j + 1) % 2)
            {
                if (k)
                {
                    k--;
                    cout << "L";
                }
                else cout << "S";
            }
            else
            {
                cout << "S";
            }
        }
        cout << endl;
    }
}