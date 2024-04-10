#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
const int mod=1e9+7;
#define MXN 2005
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<pii,int> > v;
    for(int i = 1;i<=m;i++){
        int x,w;
        scanf("%d %d",&x,&w);
        v.pb(mp(mp(w,x),i));
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<2*n;i++){
        v[i].y=-v[i].y;
        swap(v[i].x.x,v[i].x.y);
    }
    sort(v.begin(),v.end());
    vector<int> ans;
    LL res=0;
    for(auto it:v){
        if(it.y<0)ans.pb(-it.y),res+=it.x.y;
    }
    printf("%lld\n",res);
    int l=0,r=2*n-1;
    for(int i = 0;i<n;i++){
        printf("%d %d\n",ans[l],ans[r]);
        l++;
        r--;
    }
}
int main(){
    int t=1;0000;
      scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
342475
784728
394591
622354
489948
37187.5
586271
70934.1
463806
235009
528719
786392
717050
936731
250005
382783
953168
610086
*/