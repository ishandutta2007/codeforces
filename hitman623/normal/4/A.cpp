#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n&1 || n<=3) cout<<"NO";
    else cout<<"YES";
    return 0;
}