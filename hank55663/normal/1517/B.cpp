#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MAXK 2500
int vis[105][105];
void solve(){
    MEM(vis);
    int n,m;
    scanf("%d %d",&n,&m);
    int a[105][105];
    vector<pair<int,pii> > v;
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            scanf("%d",&a[i][j]);
            v.pb(mp(a[i][j],mp(i,j)));
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<m;i++){
        vis[v[i].y.x][v[i].y.y]=1;
        //printf("%d %d\n",v[i].y.x,v[i].y.y);
    }
    for(int i = 0;i<m;i++){
        int cnt=0;
        for(int j = 0;j<n;j++){
            if(vis[j][i]){
                if(!cnt)
                cnt++;
                else{
                    for(int k=i+1;k<m;k++){
                        if(!vis[j][k]){
                            swap(a[j][k],a[j][i]);
                            swap(vis[j][k],vis[j][i]);
                            break;
                        }
                    }
                }
            }
        }
        if(!cnt){
            int ok=0;
            for(int j=0;j<n;j++){
                for(int k = i+1;k<m;k++){
                    if(vis[j][k]){
                        swap(a[j][k],a[j][i]);
                        swap(vis[j][k],vis[j][i]);
                        ok=1;   
                    }
                    if(ok)break;
                }
                if(ok)break;
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/