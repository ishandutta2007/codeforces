#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
pii p[200005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 1 ;i<=n;i++)
        scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);

    for(int  i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    sort(p,p+m);
    vector<pii> v;
    for(int i = 0;i<m;i++){
        while(!v.empty()&&v.back().y<p[i].y)v.pop_back();
        v.pb(p[i]);
    }
    int Max=0,d=0;
    int ans=1;
    for(int i = 1;i<=n;i++){
        Max=max(Max,a[i]);
        d++;
        if(lower_bound(v.begin(),v.end(),mp(Max,0))==v.end()){
            printf("-1\n");
            return ;
        }
        if(lower_bound(v.begin(),v.end(),mp(Max,0))->y<d){
            d=1;
            Max=a[i];
            ans++;
            //return 0;
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       solve();
    }
}
/*
5 4
8 1 0 3 0
0 0 1 3 8
1
*/