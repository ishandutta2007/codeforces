#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
int main()
{
    int a,b,i,j,us[51][51]={};
    pair < int, int > p[51];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>p[i].fi>>p[i].se;
        us[p[i].fi][p[i].se]++;
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<a; j++ ){
            if( p[j].fi<p[j+1].fi ){
                swap( p[j].fi, p[j+1].fi );
                swap( p[j].se, p[j+1].se );
            }
            else if( p[j].fi==p[j+1].fi ){
                if( p[j].se>p[j+1].se ){
                    swap( p[j].se, p[j+1].se );
                }
            }
        }
    }
    cout<<us[p[b].fi][p[b].se];
    return 0;
}