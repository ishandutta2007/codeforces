#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool b1=1;
    int a,b,c,d=2,f,g,i;
    cin>>a>>b;
    if( b>a || b==1 && a>1 ){
        cout<<-1;
        return 0;
    }
    c=b-2;
    c=a-c+1;
    for( i=1; i<=a; i++ ){
        b1=abs( b1-1 );
        if( i<c ){
            cout<<char( b1+97 );
        } 
        else{
            cout<<char( d+97 );
            d++;
        }  
    }   
    return 0;
}

//   97    a