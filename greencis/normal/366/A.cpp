#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iomanip>
using namespace std;

int n,a[4][4];
int x,y,z;

int main()
{
    cin >> n;
    for (int i= 0; i < 4; ++i){
        for (int j = 0; j< 4;++j)
            cin>>a[i][j];
    }

    bool yes = false;

    for (int i = 0;  i < 4; ++i) {
        if (a[i][0] + a[i][2] <= n) {
            cout << i+1 << " " << a[i][0] << " " << n-a[i][0];
            return 0;
        }
        if (a[i][1] + a[i][2] <= n)  {
            cout << i+1 << " " << a[i][1] << " " << n-a[i][1];
            return 0;
        }
        if (a[i][0] + a[i][3] <= n)  {
            cout << i+1 << " " << a[i][0] << " " << n-a[i][0];
            return 0;
        }
        if (a[i][1] + a[i][3] <= n)  {
            cout << i+1 << " " << a[i][1] << " " << n-a[i][1];
            return 0;
        }
    }

    cout << -1;
    return 0;
}