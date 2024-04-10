#include <vector>
#include <algorithm>
#include <iostream>
#define INF 2147483000

using namespace std;

bool v[2000000] = {}, vis[2000000] = {};
int a[1000], b[1000];
int n, vin = 0, mv = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '+') a[i] = 1; else a[i] = -1;
        cin >> b[i];

        if (a[i] < 0)
        {
            if (!v[b[i]])
            {
                vin++;
                vis[b[i]] = true;
            }
        }
        else v[b[i]] = true;
    }
    mv = vin;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            vin++;
            vis[b[i]] = true;
        }
        else
        {
            vin--;
            vis[b[i]] = false;
        }
        if (vin > mv) mv = vin;
    }
    cout << mv;
}