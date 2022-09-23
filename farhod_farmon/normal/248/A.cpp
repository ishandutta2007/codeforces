#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,i,d[2]={0,0},d1[2]={0,0};
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b>>c;
        d[b]++;
        d1[c]++;
    }
    cout<<min( d[0], d[1] )+min( d1[0], d1[1] );
    return 0;
}