#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[101],c[500]={},d=0,i,j;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        c[b[i]]++;
    }
    c[200]=c[200]%2;
    c[100]-=c[200]*2;
    if( c[100]%2==0 && c[100]>=0 ){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}