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
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v[105];
    for(int i = 1;i<=n*k;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    pii ans[105];
    for(int i = 1;i<=n;i++)ans[i]=mp(-1,-1);
    for(int i = 1;i<=n;i+=k-1){
        vector<pii> a;
        for(int j=i;j<i+k-1&&j<=n;j++){
            for(auto it:v[j])a.pb(mp(it,j));
        }
        sort(a.begin(),a.end());
        int vis[105];
        fill(vis,vis+105,0);
        for(auto it:a){
            if(ans[it.y]!=mp(-1,-1))continue;
            if(vis[it.y]){
                ans[it.y]=mp(vis[it.y],it.x);
                fill(vis,vis+n+1,0);
            }
            else{
                vis[it.y]=it.x;
            }
        }
    }
    for(int i = 1;i<=n;i++)printf("%d %d\n",ans[i].x,ans[i].y);
}
int main(){
    int t=1;
//    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
0 1 1 1
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
x^2+y^2=kxy+k;
64+y^2=32y+4;
y^2-32y+60=0;

x^2-k*y*x-k+y*y=0;
a=1;
b=-k*y;
c=y*y-k
x=ky+-sqrt(k*k*y*y+4*k-4*y*y) 
*/