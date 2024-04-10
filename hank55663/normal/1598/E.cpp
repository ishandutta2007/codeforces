#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 500005
vector<pii> a[1005][1005];
set<int> s[2005];
int vis[1005][1005];
void solve(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    int Index=0;
    LL ans=0;
    for(int i = 1;i<=n;i++){
        int x=i,y=1;
        pii p=mp(1,0);
        int now=1;
        s[Index].insert(0);
        while(true){
            a[x][y].pb(mp(now,Index));
            now++;
            x+=p.x;
            y+=p.y;
            swap(p.x,p.y);
            if(x>n||y>m)break;
        }
        s[Index++].insert(now);
        //printf("%d\n",now);
        ans+=now*1ll*(now-1)/2;
    }
    for(int i = 1;i<=m;i++){
        int x=1,y=i;
        pii p=mp(0,1);
        int now=1;
        s[Index].insert(0);
        while(true){
           
            a[x][y].pb(mp(now,Index));
            now++;
             x+=p.x;
            y+=p.y;
            swap(p.x,p.y);
            if(x>n||y>m)break;
        }
        s[Index++].insert(now);
       //  printf("%d\n",now);
        ans+=now*1ll*(now-1)/2;
    }
    int tot=n*m;
      //printf("%lld %lld\n",ans,tot);
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        if(vis[x][y]){
            tot++;
            vis[x][y]=0;
            for(auto p:a[x][y]){
                int x=p.x,i=p.y;
                s[i].erase(x);
                auto it=s[i].lower_bound(x);
                auto it2=prev(it);
                ans+=(*it2-*it)*(*it2-*it-1)/2;
                ans-=(*it2-x)*(*it2-x-1)/2;
                ans-=(x-*it)*(x-*it-1)/2;
            }
        }
        else{
            tot--;
            vis[x][y]=1;
             for(auto p:a[x][y]){
                int x=p.x,i=p.y;
                
                auto it=s[i].lower_bound(x);
                auto it2=prev(it);
                ans-=(*it2-*it)*(*it2-*it-1)/2;
                ans+=(*it2-x)*(*it2-x-1)/2;
                ans+=(x-*it)*(x-*it-1)/2;
                s[i].insert(x);
            }
        }
        printf("%lld\n",ans-tot);
    }
}
int main(){

    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
*/