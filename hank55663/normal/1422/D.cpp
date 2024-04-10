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
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
vector<pii> v[100005];
void solve(){
    int nn,m;
    scanf("%d %d",&nn,&m);
    int sx,sy,fx,fy;
    scanf("%d %d %d %d",&sx,&sy,&fx,&fy);
    vector<pair<pii,int> > vv;
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        vv.pb(mp(mp(x,y),i));
    }
    for(int i = 1;i<=2;i++){
        sort(vv.begin(),vv.end());
        for(int a = 1;a<vv.size();a++){
            auto p1=vv[a],p2=vv[a-1];
            v[p1.y].pb(mp(p2.y,min(abs(p2.x.x-p1.x.x),abs(p2.x.y-p1.x.y))));
            v[p2.y].pb(mp(p1.y,min(abs(p2.x.x-p1.x.x),abs(p2.x.y-p1.x.y))));
        }
        for(auto &it:vv){
            swap(it.x.x,it.x.y);
        }
    }
    for(auto it:vv){
        v[0].pb(mp(it.y,min(abs(it.x.x-sx),abs(it.x.y-sy))));
        v[it.y].pb(mp(0,min(abs(it.x.x-sx),abs(it.x.y-sy))));
        v[m+1].pb(mp(it.y,abs(it.x.x-fx)+abs(it.x.y-fy)));
        v[it.y].pb(mp(m+1,abs(it.x.x-fx)+abs(it.x.y-fy)));
    }
    v[0].pb(mp(m+1,abs(sx-fx)+abs(sy-fy)));
    int dis[100005];
    fill(dis,dis+100005,-1);
    dis[0]=-1;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,0));
    while(!pq.empty()){
        pii p=pq.top();
        pq.pop();
        
        if(dis[p.y]!=-1)continue;
       // printf("%d %d\n",p.x,p.y);
        dis[p.y]=p.x;
        for(auto it:v[p.y]){
            if(dis[it.x]==-1){
                pq.push(mp(it.y+dis[p.y],it.x));
            }
        }
    }
    printf("%d\n",dis[m+1]);
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


*/
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