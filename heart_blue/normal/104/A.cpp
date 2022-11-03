#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n = n-10;
    if(n <= 0 || n >= 12) cout << 0 << endl;
    else if((n >= 1 && n <= 9 )|| n == 11) cout << 4 << endl;
    else cout << 15 << endl;

    return 0;
}