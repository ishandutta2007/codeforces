#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int n,c[10]={2,7,2,3,3,4,2,5,1,2};

int main()
{
    cin >> n;
    cout << c[n/10] * c[n%10];

    return 0;
}