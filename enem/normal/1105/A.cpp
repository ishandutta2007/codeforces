#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int lmao(int m[],int i)
{
    int s=0;
    for(int j=1;j<101;j++)
    {
        if(j<i-1) s+=m[j]*(i-j-1);
        else if(j>i+1) s+=m[j]*(j-i-1);
    }
    return s;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    int m[102];
    for(int i=0;i<102;i++) m[i]=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    int nmin=1;
    int mmin=lmao(m,1);
    for(int i=2;i<101;i++)
    {
        if(lmao(m,i)<mmin)
        {
            nmin=i;
            mmin=lmao(m,i);
        }
    }
    cout<<nmin<<' '<<mmin;
    return 0;
}