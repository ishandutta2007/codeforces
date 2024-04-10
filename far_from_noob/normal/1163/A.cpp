#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{   int n,k;
cin >>n>>k;
    if(k==0)cout<<1;
    else if(k<=n/2)cout<< k;
    else  cout<< n-k;
    //cout << "Hello world!" << endl;
    return 0;
}