#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i;
    cin>>a>>b;
    if( a>1 && b==0 ){
        cout<<"No solution";
        return 0;
    }
    cout<<b;
    a-=1;
    for( i=1; i<=a; i++ ){
        cout<<0;
    }
    return 0;
}