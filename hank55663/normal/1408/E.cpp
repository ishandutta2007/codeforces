#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define N 700005
int f[300005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int m,n;
    scanf("%d %d",&m,&n);  
    for(int j=0;j<300005;j++)f[j]=j;
    int a[100005],b[100005];
    for(int i = 1;i<=m;i++)scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++)scanf("%d",&b[i]);
    vector<pair<LL,pii> > v;
    LL ans=0;
    b[0]=1e9+7;
    for(int i = 1;i<=m;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x;
            scanf("%d",&x);
            v.pb(mp(a[i]+b[x],mp(i+n,x)));
            ans+=a[i]+b[x];
        } 
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto it:v){
        int x,y;
        tie(x,y)=it.y;
        int fx=Find(x),fy=Find(y);
        if(fx!=fy){
            ans-=it.x;
            f[fx]=fy;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/