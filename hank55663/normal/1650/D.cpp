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
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        v.pb(x);
    }
    vector<int> ans;
    for(int i = 0;i<n;i++){
        vector<int> tmp;
        for(int j = 0;j<v.size();j++){
            if(v[j]==n-i){
                ans.pb((j+1)%(v.size()));
                for(int k = j+1;k<v.size();k++)tmp.pb(v[k]);
                for(int k=0;k<j;k++)tmp.pb(v[k]);
                break;
            }
        }
        swap(tmp,v);
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)printf("%d ",it);
    printf("\n");
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