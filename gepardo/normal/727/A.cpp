#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define int long long

vector <int> res;
int a, b;

void print()
{
    cout << "YES" << endl;
    cout << res.size() + 1 << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << b << endl;
    exit(0);
}

void recurse(int a)
{
    if (a > b) return;
    if (a == b) { print(); return; }
    res.push_back(a);
    recurse(a * 2);
    recurse(a * 10 + 1);
    res.pop_back();
}

main()
{
    cin >> a >> b;
    res.clear();
    recurse(a);
    cout << "NO" << endl;
    return 0;
}