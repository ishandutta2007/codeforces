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
    if (k == n) {
        cout<<-1;
        return 0;
    }

    for (int i = 1; i <= n-k; ++i) {
        int t = i - 1;
        if (t == 0)
            t = n-k;
        cout << t << " ";
    }

    for (int i = n-k+1; i <=n ; ++i) {
        cout << i << " ";
    }

    return 0;
}