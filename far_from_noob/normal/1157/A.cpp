#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >>n;
    int a[10],flag=0,m,t=1000000000;
    for(int i=0;i<10;i++){
        a[i]= n/t;
        n=n- n /t * t;
        t=t/10;
        if(flag==0 && a[i]>0){
            flag=1;
            m=i;
        }
    }
    //cout<< a[7];
    int countans=0;
    if(m<9)countans++;
    for(int i=9;i>m;i--){
        countans+=9-a[i];
    }
    cout << countans+9 << endl;
    return 0;
}