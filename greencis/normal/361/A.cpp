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

int main()
{
    int n,k;
    cin>>n>>k;

    int table[n], z = k, m = n;
    for (int i = 0; i < n; ++i)
    {
        table[i] = z/m;
        z -= z/m;
        --m;
    }

    for (int i = 0; i < n; ++i) {
        for (int k = i; k < n; ++k) {
            cout << table[k]<<" ";
        }
        for (int k = 0; k < i; ++k) {
            cout << table[k]<<" ";
        }
        cout << endl;
    }

    return 0;
}