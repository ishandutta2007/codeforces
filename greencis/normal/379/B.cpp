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

int n,a[1000];

int main()
{
    cin >> n;
    for (int i = 0; i <n;++i) {
        cin >> a[i];
        bool first = true;
        for (int j = 0; j < a[i]; ++j) {
            if (!first) {
                if (i == 0) {
                    cout << "RL";
                } else cout << "LR";
            }
            first = false;
            cout << 'P';
        }
        if (i != n-1)
            cout << 'R';
    }



    return 0;
}