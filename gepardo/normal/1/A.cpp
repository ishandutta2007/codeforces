#include <iostream>
#include <string>
#define int long long

using namespace std;

main()
{
    int a, b, c; cin >> a >> b >> c;
    cout << (((a - 1) / c) + 1) * (((b - 1) / c) + 1);
}