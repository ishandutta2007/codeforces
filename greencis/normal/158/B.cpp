#include <iostream>

using namespace std;

int main()
{
    int n,freq[4]={},t;
    cin >> n;
    while (n--)
        cin>>t,++freq[t-1];
    cout<<freq[3] + freq[2] + (freq[1] * 2 + max(freq[0]-freq[2], 0) + 3) / 4;
    return 0;
}