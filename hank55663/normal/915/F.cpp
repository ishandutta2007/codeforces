#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
vector<int> v[1000005];
pii p[1000005];
int f[1000005];
int ok[1000005];
int Size[1000005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i+1);
    }
    int m=n-1;
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    sort(p,p+n);
    for(int i = 1;i<=n;i++)
        f[i]=i;
    LL ans=0;
    for(int i = 0;i<n;i++){
        LL tot=1;
        LL sub=0;
        for(auto it:v[p[i].y])
            if(ok[it]){
                int fit=Find(it);
                tot+=Size[fit];
                sub+=(LL)Size[fit]*Size[fit];
                f[fit]=p[i].y;
            }
        ok[p[i].y]=1;
        Size[p[i].y]=tot;
        ans -= (tot*tot-sub)*p[i].x;
    }
    reverse(p,p+n);
    for(int i = 1;i<=n;i++)
        f[i]=i,ok[i]=0;
    for(int i = 0;i<n;i++){
        LL tot=1;
        LL sub=0;
        for(auto it:v[p[i].y])
            if(ok[it]){
                int fit=Find(it);
                tot+=Size[fit];
                sub+=(LL)Size[fit]*Size[fit];
                f[fit]=p[i].y;
            }
        ok[p[i].y]=1;
        Size[p[i].y]=tot;
        ans += (tot*tot-sub)*p[i].x;
    }
    printf("%lld\n",-ans/2);
}
/*

262143999937856
*/