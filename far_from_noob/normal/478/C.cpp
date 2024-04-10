#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    long long count=0;
    if(a[2]-a[0] >=2*( a[1] -a[0])){
        count+= a[1]-a[0];
        a[2]-= 2*count;
        a[1]=a[0];
        if(a[2]>=4*a[0])count+=2*a[0];
        else count+=(a[2]+a[1]+a[0])/3;
    }
    else{
        count+= a[0] + (a[2] - a[0] + a[1] -a[0])/3;

    }
    cout<<count;
    return 0;
}