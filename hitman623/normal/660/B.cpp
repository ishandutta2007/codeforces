#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,m,a[100][4]={0},i,l=1;
    cin>>n>>m;
    while(l<=m)
    {
        for(i=n-1;i>=0;i--)
            {if(l>m) break;
            a[i][0]=l++;
            if(l>m) break;
            a[i][3]=l++;}
        for(i=n-1;i>=0;i--)
            {if(l>m) break;
            a[i][1]=l++;
            if(l>m) break;
            a[i][2]=l++;}
    }
    for(i=n-1;i>=0;--i)
    {
        if(a[i][1])
        cout<<a[i][1]<<" ";
        if(a[i][0])
        cout<<a[i][0]<<" ";
        if(a[i][2])
        cout<<a[i][2]<<" ";
        if(a[i][3])
        cout<<a[i][3]<<" ";
    }

    return 0;
}