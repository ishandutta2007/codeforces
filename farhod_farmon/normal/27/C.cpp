#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool b1=false, b2=false,b3=false,b4=false;
    int a,b[100001],i,j,h,a1,a2,a3;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        if( i>1 && b[i]>b[i-1] ){
            b1=true;
        }
        else if( i>1 && b[i]<b[i-1] ){
            b2=true;
        }
    }
    if( b1==false || b2==false ){
        cout<<0;
        return 0;
    }
    b1=false;
    b2=false;
    for( i=1; i<=a; i++ ){
        if( b[i]<b[i+1] && b[i+1]>b[i+2] && i<a-1 ){
            cout<<"3\n"<<i<<" "<<i+1<<" "<<i+2;
            return 0;
        }
        else if( b[i]>b[i+1] && b[i+1]<b[i+2] && i<a-1 ){
            cout<<"3\n"<<i<<" "<<i+1<<" "<<i+2;
            return 0;
        }
        else if( b[i]<b[i+1] && b[i+1]==b[i+2] ){
            for( j=i+2; j<=a; j++ ){
                if( b[j]<b[j+1] ){
                    i=j;
                    break;
                }
                else if( b[j]>b[j+1] ){
                    cout<<"3\n"<<i<<" "<<i+1<<" "<<j+1;
                    return 0;
                }
            }
        }
        else if( b[i]>b[i+1] && b[i+1]==b[i+2] ){
            for( j=i+2; j<=a; j++ ){
                if( b[j]>b[j+1] ){
                    i=j;
                    break;
                }
                else if( b[j]<b[j+1] ){
                    cout<<"3\n"<<i<<" "<<i+1<<" "<<j+1;
                    return 0;
                }
            }
        }
    }
    return 0;
}