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

int a,b,w,d,l;

int main()
{
    cin >> a >> b;
    //for (int i = 1; i <= 6; ++i){
        for (int j = 1; j <= 6; ++j) {
            if (abs(a-j) > abs(b-j))
                ++w;
            else if (abs(a-j) == abs(b-j))
                ++d;
            else ++l;
        }
   // }

    cout << l << " " << d << " "<< w;

    return 0;
}