#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    long double l,r,k,i=0,t=1,f=0;
    cin>>l>>r>>k;
    while(t<=r)
    {
        t=pow(k,i++);
        if(t>=l && t<=r)
        {cout<<(long long )t<<" ";f=1;}
        if(t==r) break;
    }
    if(f==0)
        cout<<-1;

    return 0;
}