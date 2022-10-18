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

long long a,b,res = 0;

int main()
{
    cin >> a >> b;
    long long q = 0;
    while (a) {
        res += a;
        long long q1 = q, a1 = a;
        a = (a1 + q1) / b;
        q = a1 + q1 - a * b;
        //cout << a << " " << b << " " << q<< " "<<res<<endl;
    }
    cout << res;

    return 0;
}