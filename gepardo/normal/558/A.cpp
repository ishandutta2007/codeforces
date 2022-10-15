#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int p[2][1000], q[2][1000];
    int pc[2];
    int n, sum;
    pc[0] = 0; pc[1] = 0;
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        sum += b;
        if (a < 0)
        {
            p[0][pc[0]] = -a;
            q[0][pc[0]] = b;
            pc[0]++;
        }
        if (a > 0)
        {
            p[1][pc[1]] = a;
            q[1][pc[1]] = b;
            pc[1]++;
        }
    }
    int u;
    for (int t = 0; t < 2; t++)
        for (int i = 0; i < pc[t]; i++)
            for (int j = 1; j < pc[t]; j++)
                if (p[t][j - 1] < p[t][j])
                {
                    u = p[t][j - 1];
                    p[t][j - 1] = p[t][j];
                    p[t][j] = u;
                    u = q[t][j - 1];
                    q[t][j - 1] = q[t][j];
                    q[t][j] = u;
                }
    /*for (int t = 0; t < 2; t++)
    {
        cout << pc[t] << ": ";
        for (int i = 0; i < pc[t]; i++)
            cout << q[t][i] << " ";
        cout << endl;
    }*/
    if (pc[0] > pc[1])
    {
        for (int i = 0; i < pc[0] - pc[1] - 1; i++)
            sum -= q[0][i];
    }
    else
    {
        for (int i = 0; i < pc[1] - pc[0] - 1; i++)
            sum -= q[1][i];
    }
    cout << sum;
}