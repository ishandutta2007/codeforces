#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
vector<pii> r[200005],l[200005];
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    map<int,int> m;

    for(int i = 0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int len=b-a+1;
        l[a].pb(mp(len,c));
        r[b].pb(mp(len,c));
    }
    int ans=2e9+5;
    for(int i = 1;i<=2e5;i++){
        for(auto it:l[i]){
          //  printf("%d\n",x-it.x);
            if(m.find(x-it.x)!=m.end()){
                ans=min(ans,it.y+m[x-it.x]);
            }
        }
        for(auto it:r[i]){
            if(m.find(it.x)==m.end())
                m[it.x]=it.y;
            else
                m[it.x]=min(m[it.x],it.y);
        }
    }
    if(ans==2e9+5)ans=-1;
    printf("%d\n",ans);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/