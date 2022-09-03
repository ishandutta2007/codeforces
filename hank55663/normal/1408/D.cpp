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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    pii p[2005],q[2005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    for(int i =0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        q[i]=mp(x,y);
    }
    vector<pii> v;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            v.pb(mp(q[j].x-p[i].x+1,q[j].y-p[i].y+1));
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int ans=1e9;
    int Max=0;
    for(int i = 0;i<v.size();i++){
        ans=min(ans,Max+max(v[i].x,0));
      //    printf("%d %d\n",Max,max(v[i].x,0));
        Max=max(Max,v[i].y);
        //printf("%d %d\n",Max,max(v[i].x,0));
    }
   // printf("%d\n",Max);
    ans=min(ans,Max);
    printf("%d\n",ans);
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