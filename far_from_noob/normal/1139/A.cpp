#include <iostream>

using namespace std;

int main()
{
    int  n,countans=0;
    cin >>n;
    char a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if((a[i]-'0')%2==0)
        countans+=i+1;
    }
    cout<< countans;


    return 0;
}