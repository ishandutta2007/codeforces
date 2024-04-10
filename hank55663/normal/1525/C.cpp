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
#define MXN 200005
int from[300005],back[300005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x[300005];
    for(int i = 0;i<n;i++)scanf("%d",&x[i]);
    char c[300005];
    for(int i = 0;i<n;i++)
    scanf(" %c",&c[i]);
    int ans[300005];
    fill(ans,ans+300005,-1);
    vector<pair<int,pair<int,char> > > v[2];
    for(int i = 0;i<n;i++){
        if(x[i]%2)
            v[1].pb(mp(x[i],mp(i,c[i])));
        else{
            v[0].pb(mp(x[i],mp(i,c[i])));
        }
    }
    for(int t = 0;t<2;t++){
        sort(v[t].begin(),v[t].end());
        priority_queue<pair<int,pii> ,vector<pair<int,pii> > ,greater<pair<int,pii> > > pq;
        for(int i = 0;i+1<v[t].size();i++){
            int dis=v[t][i+1].x-v[t][i].x;
            if(v[t][i].y.y=='L')dis+=v[t][i].x*2;
            if(v[t][i+1].y.y=='R')dis+=(m-v[t][i+1].x)*2;
            pq.push(mp(dis,mp(i,i+1)));
            from[i]=i-1;
            back[i]=i+1;
            from[i+1]=i;
            back[i+1]=i+2;
        }
        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            int x=a.y.x,y=a.y.y;
            if(ans[v[t][x].y.x]==-1&&ans[v[t][y].y.x]==-1){
               // printf("%d %d %d\n",x,y,a.x);
                ans[v[t][x].y.x]=ans[v[t][y].y.x]=a.x/2;
                int f1=from[x],f2=back[y];
                if(f1!=-1)back[f1]=f2;
                if(f2!=v[t].size())from[f2]=f1;
                if(f1!=-1&&f2!=v[t].size()){
                    int dis=v[t][f2].x-v[t][f1].x;
                    if(v[t][f1].y.y=='L')dis+=v[t][f1].x*2;
                    if(v[t][f2].y.y=='R')dis+=(m-v[t][f2].x)*2;
                    pq.push(mp(dis,mp(f1,f2)));
                }
            }
        }
    }
    for(int i = 0;i<n;i++)printf("%d ",ans[i]);
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*
a b
b a
b a a
a a b
a a b b
a b b a
a b b a a
a b a a b
a b a b a

*/