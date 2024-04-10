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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[100005];
int vis[100005];
void solve(){
    int n,m;
    scanf("%d %d",&m,&n);
    pii Max[100005];
    MEM(Max);
    LL sum=0;
    int r=1e9,l=0;
    for(int i = 0;i<m;i++){
        v[i].clear();
        for(int j = 0;j<n;j++){
            int x;
            scanf("%d",&x);
            v[i].pb(x);
            Max[j]=max(Max[j],mp(x,i));        
        }
      
    }
    for(int j = 0;j<n;j++)  r=min(r,Max[j].x);
    r++;
    while(r>l+1){
        int mid=(r+l)/2;
        int ok=0;
        for(int i = 0;i<m;i++){
            int cnt=0;
            for(int j = 0;j<n;j++){
                if(v[i][j]>=mid)cnt++;
            }
            if(cnt>=2)ok=1;
        }
        if(ok)l=mid;
        else r=mid;
    }
    printf("%d\n",l);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}