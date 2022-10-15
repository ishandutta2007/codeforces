#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c = 0;
    cin >> n;
    vector <int> v(n + 1); v[n] = 2;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++)
        if (v[i] == 1)
        {
            for (int j = i; j < n; j++)
            {
                int q;
                if (v[j] == 0)
                {
                    if (v[j + 1] == 2) break;
                    if (v[j + 1] == 1)
                    {
                        c++;
                        continue;
                    }
                    while (v[j] == 0) j++;
                    if (v[j] == 2) break;
                    j--;
                }
                else c++;
            }
            break;
        }
    cout << c;
}