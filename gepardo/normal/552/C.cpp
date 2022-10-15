#include <iostream>
#include <cstdio>
using namespace std;


int a[100], v[100];
int count = 0;
bool yes = false;
int w, m;

bool check()
{
    if (yes) return false;
    int q[100] = {}, s[100] = {};
    // v = a - q
    // q = a - v
    for (int i = 0; i < count; i++)
    {
        int u = a[i] - v[i] + s[i];
        if (u < 0)
        {
            u += w;
            s[i + 1] = -1;
        }
        q[i] = u;
    }

    if (q[count] < 0) return false;

    for (int i = 0; i < count; i++)
        if (q[i] > 1) return false;

    /*for (int i = count - 1; i >= 0; i--)
        cout << q[i] << " ";
    cout << endl;

    for (int i = count - 1; i >= 0; i--)
        cout << a[i] << " ";
    cout << endl;

    for (int i = count - 1; i >= 0; i--)
        cout << v[i] << " ";
    cout << endl;

    cout << "----------------" << endl;*/

    return true;
}

void gen(int step)
{
    if (step == count)
    {
        if (check())
            yes = true;
        return;
    }
    a[step] = 0;
    gen(step + 1);
    a[step] = 1;
    gen(step + 1);
}

int main()
{
    cin >> w >> m;
    if (w == 2 || w == 3)
    {
        cout << "YES";
        return 0;
    }
    while (m != 0)
    {
        v[count] = m % w;
        count++;
        m /= w;
    }
    v[count] = 0;
    count++;
    v[count] = 0;
    count++;
    gen(0);
    if (yes)
         cout << "YES";
    else cout << "NO";
}