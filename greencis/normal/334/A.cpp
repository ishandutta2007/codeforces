#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= (n*n)/2; ++i)
        cout << i << " " << n*n+1-i<<"\n";
    return 0;
}