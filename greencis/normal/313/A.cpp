#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = n%10;
    cout << max(n,max(n/10,(n/100)*10+x));
    return 0;
}