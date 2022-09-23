#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,cnt=0,d,i,j;
    char c[3001];
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }
    for( i=1; i<=a; i++ ){
        if( c[i]=='L' ){
            for( j=i; j>=1; j-- ){
                if( c[j]=='R' ){
                    c[j]='I';
                    if( ( i-j )%2==0 ){
                        cnt++;
                    }
                    break;
                }
                c[j]='I';
            }
        }
        if( c[i]=='R' ){
            for( j=i; j<=a; j++ ){
                if( c[j]=='L' ){
                    c[j]='I';
                    if( ( j-i )%2==0 ){
                        cnt++;
                    }
                    break;
                }
                c[j]='I';
            }
            i=j;
        }
    }
    for( i=1; i<=a; i++ ){
        if( c[i]=='.' ){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}