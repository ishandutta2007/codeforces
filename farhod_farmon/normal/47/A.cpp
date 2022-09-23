#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,i=1;
    cin>>a;
    while( i*(i-1)/2<a ){
        i++;
    }
    if( i*(i-1)/2==a ){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}