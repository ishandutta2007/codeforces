#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,c[1000001],cnt=0;
    cin>>a>>b;
    for( i=b+1; i<=a; i++ ){
        cnt++;
        c[i]=cnt;
    }
    for( i=b; i>=1; i-- ){
        cnt++;
        c[i]=cnt;
    }
    for( i=1; i<=a; i++ ){
        cout<<c[i]<<" ";
    }
    return 0;
}