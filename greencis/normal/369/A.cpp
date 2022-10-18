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
    int n,m,k;
    cin >> n>>m>>k;
    int a[n];
    int m1=m,k1=k,res=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if (a[i] == 1) {
            m1--;
            if (m1 == -1) {
                m1 = 0;
                ++res;
            }
        }
        else if (k1 > 0) {
            k1--;
        } else {
            m1--;
            if (m1 == -1) {
                m1 = 0;
                ++res;
            }
        }
    }
    cout << res;

    return 0;
}