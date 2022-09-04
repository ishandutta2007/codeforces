#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[105][105];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            char c;
            scanf(" %c",&c);
            a[i][j]=c-'0';
        }
    }
    vector<vector<pii> > v;
    for(int i = 1;i<=n-2;i++){
        for(int j = 1;j<=m-2;j++){
            if(a[i][j]==1){
                v.pb({mp(i,j),mp(i+1,j),mp(i,j+1)});
                a[i][j]^=1;
                a[i+1][j]^=1;
                a[i][j+1]^=1;
            }
        }
        if(a[i][m-1]==0&&a[i][m]==0);
        else{
            vector<pii> tmp;
            if(a[i][m-1]==1)tmp.pb(mp(i,m-1)),a[i][m-1]^=1;
            if(a[i][m]==1)tmp.pb(mp(i,m)),a[i][m]^=1;
            tmp.pb(mp(i+1,m-1));
            if(tmp.size()!=3){
                tmp.pb(mp(i+1,m));
                a[i+1][m]^=1;
            }
            a[i+1][m-1]^=1;
            v.pb(tmp);
        }
    }
    for(int i = 1;i<=m-2;i++){
        if(a[n-1][i]==0&&a[n][i]==0);
        else{
             vector<pii> tmp;
            if(a[n-1][i]==1)tmp.pb(mp(n-1,i)),a[n-1][i]^=1;
            if(a[n][i]==1)tmp.pb(mp(n,i)),a[n][i]^=1;
            tmp.pb(mp(n-1,i+1));
            if(tmp.size()!=3){
                tmp.pb(mp(n,i+1));
                a[n][i+1]^=1;
            }
            a[n-1][i+1]^=1;
            v.pb(tmp);
        }
    }
    vector<pii> vv;
    for(int i = n-1;i<=n;i++){
        for(int j = m-1;j<=m;j++){
            if(a[i][j]){
                vv.pb(mp(i,j));
            }
        }
    }
    if(vv.size()==3)v.pb(vv);
    else{
        vector<vector<pii>> tmp;
        vector<pii> p;
        for(int i = n-1;i<=n;i++){
            for(int j = m-1;j<=m;j++){
                p.pb(mp(i,j));
            }
        }
        for(int i = 0;i<4;i++){
            vector<pii> pp;
            for(int j = 0;j<4;j++){
                if(i!=j)pp.pb(p[j]);
            }
            tmp.pb(pp);
        }
        for(int i=0;i<(1<<4);i++){
            for(int j = 0;j<4;j++){
                if(i&(1<<j)){
                    for(auto it:tmp[j])
                    a[it.x][it.y]^=1;
                }
            }
            int ok=1;
            for(int j=n-1;j<=n;j++){
                for(int k =m-1;k<=m;k++){
                    if(a[j][k])ok=0;
                }
            }
            if(ok){
              //  printf("? %d\n",j);
                for(int j = 0;j<4;j++){
                    if(i&(1<<j)){
                        v.pb(tmp[j]);
                    }
                }
                break;
            }
            else{
                for(int j = 0;j<4;j++){
                    if(i&(1<<j)){
                        for(auto it:tmp[j])
                        a[it.x][it.y]^=1;
                    }
                }
            }
        }
    }
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d %d %d %d %d %d\n",it[0].x,it[0].y,it[1].x,it[1].y,it[2].x,it[2].y);
    }
}

int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}