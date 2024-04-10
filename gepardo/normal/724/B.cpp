#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[30][30];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
                swap(a[k][i], a[k][j]);
            bool ok = true;
            for (int k = 0; k < n; k++)
            {
                int dif = 0;
                for (int l = 0; l < m; l++)
                    if (l+1 != a[k][l]) dif++;
                if (dif > 2) ok = false;
            }
            for (int k = 0; k < n; k++)
                swap(a[k][i], a[k][j]);
            if (ok)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    cout << "NO" << endl;
    return 0;
}