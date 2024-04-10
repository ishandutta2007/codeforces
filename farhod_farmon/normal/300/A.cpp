#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[101],i,j,cnt=0,c=0,d=0,f=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        if( b[i]<0 ){
            c++;
        }
        else if( b[i]==0 ){
            d++;
        }
        else{
            f++;
        }
    }
    cout<<1<<" ";
    c--;
    for( i=1; i<=a; i++ ){
        if( b[i]<0 ){
            cout<<b[i]<<endl;
            b[i]=9999;
            break;
        }
    }
    if( c%2!=0 ){
        c--;
        cnt++;
    }
    cout<<c+f<<" ";
    for( i=1; i<=a; i++ ){
        if( b[i]==0 || b[i]==9999 ){
            continue;
        }
        if( c<=0 && b[i]<0 ){
            continue;
        }
        if( b[i]<0 ){
            c--;
        }
        cout<<b[i]<<" ";
        b[i]=9999;
    }
    cout<<endl;
    cout<<d+cnt<<" ";
    for( i=1; i<=a; i++ ){
        if( b[i]==9999 ){
            continue;
        }
        cout<<b[i]<<" ";
    }
    return 0;
}