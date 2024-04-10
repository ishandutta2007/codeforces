#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    cout << m + n - 1 <<endl;
    for (int i = 1; i <= m; ++i)
        cout << "1 " << i<<endl;
    for (int j = 2; j <= n; ++j)
        cout << j << " 1"<<endl;
    return 0;
}