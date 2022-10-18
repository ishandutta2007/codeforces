#include <iostream>

using namespace std;

char z[9][9];

int main()
{
    cin>>z[0]>>z[1]>>z[2]>>z[3];

    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            int q = 0;
            if (z[i][j] == '#') ++q;
            if (z[i][j+1] == '#') ++q;
            if (z[i+1][j] == '#') ++q;
            if (z[i+1][j+1] == '#') ++q;
            if (q != 2) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}