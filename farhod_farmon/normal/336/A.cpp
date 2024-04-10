#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if( a>=0 && b>=0 ){
        cout<<0<<" "<<a+b<<" "<<a+b<<" "<<0;
    }
    if( a<0 && b>=0 ){
        a*=-1;
        cout<<"-"<<a+b<<" "<<0<<" "<<0<<" "<<a+b;
    }
    else if( a>0 && b<0 ){
        b*=-1;
        cout<<0<<" -"<<a+b<<" "<<a+b<<" "<<0;
    }
    else if( a<0 && b<0 ){
        a*=-1;
        b*=-1;
        cout<<"-"<<a+b<<" "<<0<<" "<<0<<" -"<<a+b;
    }
    return 0;
}