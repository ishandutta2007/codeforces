#include <iostream>

using namespace std;

int tree[100001], n;

int get(int r)
{
    int result = 0;
    for (; r > 0; r -= r & (-r))
        result += tree[r];
    return result;
}

void add(int a, int x)
{
    for (; a <= n; a += (a & (-a)))
        tree[a] += x;
}

int main(void)
{
    int k, n2, kk;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> kk;
        k = i;
        add(i, kk);
        n2 = 1;
        while (n2 * 2 + k <= n)
            n2 *= 2;
        while (k < n)
        {
            if (n2 + k <= n)
            {
                k += n2;
                add(k, kk);
            }
            n2 /= 2;
        }
    }
    for (int i = 1; i < n; ++i)
        cout << get(i) << endl;
    return 0;
}