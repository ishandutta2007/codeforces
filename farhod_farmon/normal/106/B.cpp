#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,speed[101],ram[101],hdd[101],cost[101],i,j,ans,cnt=1001;
    bool b[101];
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>speed[i]>>ram[i]>>hdd[i]>>cost[i];
    }
    for( i=1; i<=a; i++ ){
        b[i]=true;
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            if( speed[j]>speed[i] && ram[j]>ram[i] && hdd[j]>hdd[i] ){
                b[i]=false;
                break;
            }
        }
    }
    for( i=1; i<=a; i++ ){
        if( b[i]==true ){
            if( cost[i]<cnt ){
                cnt=cost[i];
                ans=i;
            }
        }
    }
    cout<<ans;
    return 0;
}