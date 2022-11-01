#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >>n;
    char a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int f[10];
    for(int i=1;i<10;i++){
        cin>>f[i];
    }
    //cout<< 'a[0]';

    //int k = a[0]-'0';
    //cout<<k;
    int flag=1;
    for(int i=0;i<n;i++){
        if(a[i]-'0'< f[a[i] - '0']  && flag!=2){
                flag=0;
                cout<< f[a[i]-'0'];
        }
        else if(a[i]-'0'== f[a[i] - '0'] )cout<< a[i]-'0';
        else {
            if(flag==0)flag=2;
            cout<< a[i]-'0';
        }
    }
    return 0;
}