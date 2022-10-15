#include <iostream>
#include <set>

using namespace std;

set<int> sqset;

bool isSquare(int n)
{
    return sqset.find(n) != sqset.end();
}

bool ok(int n)
{
    if (n%2 != 0)
        return false;
    if (isSquare(n/2))
        return true;
    return n%4 == 0 && isSquare(n/4);
}

int main()
{
    for (int i=1;i<31623;i++)
        sqset.insert(i*i);
    int TT; cin >> TT;
    for (int tt=0;tt<TT;tt++)
    {
        int n;
        cin >> n;
        if (ok(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}