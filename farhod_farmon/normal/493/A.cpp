#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    long long int a,b[101],c[101],d[101]={0},f[101]={0},i;
    char c1[101],c2[101];
    cin>>s1>>s2>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i]>>c1[i]>>c[i]>>c2[i];
    }
    for( i=1; i<=a; i++ ){
        if( c1[i]=='a' ){
            if( c2[i]=='r' && d[c[i]]<=1 ){
                cout<<s2<<" "<<c[i]<<" "<<b[i]<<"\n";
                d[c[i]]=5;
            }
            else if( c2[i]=='y' ){
                d[c[i]]++;
            }
            if( d[c[i]]==2 ){
                cout<<s2<<" "<<c[i]<<" "<<b[i]<<"\n";
                d[c[i]]=5;
            }
        }
        else{
            if( c2[i]=='r' && f[c[i]]<=1 ){
                cout<<s1<<" "<<c[i]<<" "<<b[i]<<"\n";
                f[c[i]]=5;
            }
            else if( c2[i]=='y' ){
                f[c[i]]++;
            }
            if( f[c[i]]==2 ){
                cout<<s1<<" "<<c[i]<<" "<<b[i]<<"\n";
                f[c[i]]=5;
            }
        }
    }

    return 0;
}