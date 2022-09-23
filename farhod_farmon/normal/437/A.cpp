#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s[5],ans="C";
    int a=4,b[5],c=0,d=0,cnt=0,i,j;
    cin>>s[1]>>s[2]>>s[3]>>s[4];
    b[1]=s[1].size()-2;
    b[2]=s[2].size()-2;
    b[3]=s[3].size()-2;
    b[4]=s[4].size()-2;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            if( b[i]>=b[j]*2 && i!=j ){
                c++;
            }
            else if( b[i]*2<=b[j] && i!=j ){
                d++;
            }
        }
        if( d==3 || c==3 ){
            cnt++;
            ans=s[i][0];
        }
        if( cnt>=2 ){
            ans="C";
        }
        d=0;
        c=0;
    }
    cout<<ans;
    return 0;
}