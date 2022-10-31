#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n%2) cout << "-1";
    else for (int i=1; i<=n; i++)
    cout << ((i%2) ? i+1 : i-1) << ' ';
    return 0;
}