#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,temp2=0;
    cin >>n;
    int  a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int value[n];
    for(int i=0;i<n;i++){
        if(i< n-i-1)value[i]= a[i] /( n-i-1) ;
        else value[i]=a[i]/ i;
    }
    //\cout<< value[0]<< value[1]<<value[2];
    sort(value, value+n);
    cout<<  value[0];

    return 0;
}