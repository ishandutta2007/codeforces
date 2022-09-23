#include <bits/stdc++.h>
using namespace std;
bool b=false;
string s;
int a,c,d=0,i,j;
int main()
{
    cin>>s;
    a=s.size()-1;
    for( i=0; i<=a; i++ ){
        if( s[i]=='.' ){
            if( s[i-1]=='9' ){
                cout<<"GOTO Vasilisa.";
                return 0;
            }
            j=i-1;
            b=true;
            if( s[i+1]>='5' ){
                d=1;
            }
            break;
        }
    }
    if( b==false ){
        j=a;
    }
    for( i=0; i<j; i++ ){
        cout<<s[i];
    }
    s[j]+=d;
    cout<<s[j];
    return 0;
}