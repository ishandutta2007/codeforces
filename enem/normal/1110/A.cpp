#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int b,k;
    cin>>b>>k;
    if(b%2)
    {
        int t=0;
        for(int i=0;i<k;i++)
        {
            int temp;
            cin>>temp;
            if(temp%2) t++;
        }
        if(t%2) cout<<"odd";
        else cout<<"even";
    }
    else
    {
        int a[k];
        for(int i=0;i<k;i++)
        {
            cin>>a[k-1-i];
        }
        if(a[0]%2) cout<<"odd";
        else cout<<"even";
    }
    return 0;
}