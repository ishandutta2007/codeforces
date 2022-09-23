#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[100001],cnt=0,x,y,i,j,d=0,f=99999999;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        d=max( d, b[i] );
    }
    b[a+1]=d;
    b[0]=0;
    for( i=1; i<a; i++ ){
        if( b[i]>b[i+1] ){
            cnt++;
            x=i;
            for( j=i; j<a; j++ ){
                if( b[j]<=b[j+1] ){
                    break;
                }
            }
            if( b[j]<b[i-1] || b[i]>b[j+1] ){
                cout<<"no";
                return 0;
            }
            i=j;
            y=i;
        }
        if( cnt==2 ){
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes\n";
    if( x==0  ){
        cout<<"1 1";
        return 0;
    }
    cout<<x<<" "<<y;
    return 0;
}