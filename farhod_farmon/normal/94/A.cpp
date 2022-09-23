#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,s1[11],s2[11];
    int  a=10,i,j=0,ans=0,g=0;
    cin>>s;
    for( i=0; i<a; i++ ){
        cin>>s1[i];
    }
    j=0;
    for( j=0; j<s.size(); j++ ){
        s2[g]+=s[j];
        if( ( j+1 )%10==0 ){
            g++;
        }
    }
    for( i=0; i<a; i++ ){
        for( j=0; j<a; j++ ){
            if( s2[i]==s1[j] ){
                cout<<j;
                break;
            }
        }
    }
    return 0;
}