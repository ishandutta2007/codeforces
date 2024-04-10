#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b[1000001],i,f,d=0,g=999999999,h=0;
    bool b1=false;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    sort( b+1, b+a+1 );
    if( a<=1 ){
        cout<<-1;
        return 0;
    }
    if( a==2 ){
        f=b[2]-b[1];
        if( b[1]==b[2] ){
            cout<<1<<endl<<b[1];
        }
        else if( (b[2]-b[1])%2==0 ){
            cout<<3<<endl<<b[1]-f<<" "<<b[1]+(f/2)<<" "<<b[2]+f;
        }
        else{
            cout<<2<<endl<<b[1]-f<<" "<<b[2]+f;
        }
        return 0;
    }
    d=b[2]-b[1];
    for( i=1; i<a; i++ ){
        if( b[i+1]-b[i]<d ){
            d=b[i+1]-b[i];
        }
    }
    for( i=1; i<=a; i++ ){
        if( b[i+1]-b[i]>d ){
            if( (b[i+1]-b[i])%2!=0 ){
                cout<<0;
                return 0;
            }
            else if( (b[i+1]-b[i])/2!=d ){
                cout<<0;
                return 0;
            }
            else{
                if( b1==true ){
                    cout<<0;
                    return 0;
                }
                b1=true;
                g=b[i];
            }
        }
    }
    if( g!=999999999 ){
        cout<<1<<endl<<g+d;
    }
    else{
        if( b[1]==b[2] ){
            cout<<1<<endl<<b[1];
            return 0;
        }
        cout<<2<<endl<<b[1]-d<<" "<<b[a]+d;
    }
    return 0;
}