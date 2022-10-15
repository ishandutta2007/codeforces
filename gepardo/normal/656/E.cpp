#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[1000][1000];

int getOne(int x, int y)
{
    cin >> a[x][y]; return 0;
}

int getArray(int x, int y)
{
    return y ? getArray(x, y - 1) + getOne(x, y) : 0;
}

int getAll(int x)
{
    return x ? getAll(x - 1) + getArray(x, n) : 0;
}

int doFloydOne(int k, int i, int j)
{
    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int doFloyd3(int k, int i, int j)
{
    return j ? doFloyd3(k, i, j - 1) + doFloydOne(k, i, j) : 0;
}

int doFloyd2(int k, int i)
{
    return i ? doFloyd2(k, i - 1) + doFloyd3(k, i, n) : 0;
}

int doFloyd1(int k)
{
    return k ? doFloyd1(k - 1) + doFloyd2(k, n) : 0;
}

int findMax2(int x, int y)
{
    return y ? max(findMax2(x, y - 1), a[x][y]) : 0;
}

int findMax1(int x)
{
    return x ? max(findMax1(x - 1), findMax2(x, n)) : 0;
}

int main()
{
    cin >> n;
    getAll(n);
    doFloyd1(n);
    cout << findMax1(n);
}