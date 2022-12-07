#include <iostream>

using namespace std;

int main(void)
{
    int w;
    cin >> w;
    if ((w % 2) || (w == 2))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}