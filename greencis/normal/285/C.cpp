#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

int n,a[500005];
long long sum;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for (int i = 0; i < n; ++i) {
        sum += abs(i+1 - a[i]);
    }
    cout << sum;
    return 0;
}