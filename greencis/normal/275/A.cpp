#include <iostream>

using namespace std;

int t,d[9][9];

int main()
{
    for(int i = 1; i <= 3; ++i)
    for(int j = 1; j <= 3; ++j) {
        cin >> t;
        while (t--)
        {
            d[i][j] = !d[i][j];
            d[i][j-1] = !d[i][j-1];
            d[i][j+1] = !d[i][j+1];
            d[i-1][j] = !d[i-1][j];
            d[i+1][j] = !d[i+1][j];
        }
    }

    for(int i = 1; i <= 3; ++i) {
    for(int j = 1; j <= 3; ++j)
        cout << !d[i][j];
    cout<<endl;
    }
    return 0;
}