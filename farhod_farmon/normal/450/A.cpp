#include <bits/stdc++.h>

using namespace std;



int main ()
{
    int a,b,c[100000],d[100000],e=0,g=0,x=1,k=0;
    cin >>a>>b;
    for( int i=0; i<a; i++ ){
        cin >>d[i];
        c[i]=i+1;
    }
    for( int i=0; i<a; i++ ){
        if( d[i] > b ){
            d[i] = d[i] - b;
            d[a] = d[i];
            c[a] = c[i];
            a++;
            e++;
        }
    }
    if( e == 0 ){
        cout <<c[a-1];
        return 0;
    }
    cout <<c[a-1];
}