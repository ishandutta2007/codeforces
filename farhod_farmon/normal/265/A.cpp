#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    int a,g=0,i,j;
    cin>>s>>t;
    a=t.size();
    for( i=0; i<a; i++ ){
        if( t[i]==s[g] ){
            g++;
        }
    }
    cout<<g+1;
    return 0;
}