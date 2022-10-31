#include <iostream>

using namespace std;

int k, a[111][111], v=2, i=0;

int main()
{
    cin >> k;
    while(k>0) {
        if (k<i) i=0, v++;
        a[v-1][i]++;
        a[i][v-1]++;
        k-=i;
        i++;
        if (i>=v-1&&k>0) i=0, v++;
    }
    cout << v << endl;
    for (int i=0; i<v; i++) {for (int j=0; j<v; j++) cout << a[i][j]; cout << endl; }
    return 0;
}