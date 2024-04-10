#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    vector<vector<int> > v;
    int cnt[205];
    fill(cnt,cnt+n+1,0);
    vector<int> e[205];
    int vis[205];
    int ok[205];
    for(int i = 1;i<=n;i++)e[i].clear();
    for(int i = 0;i<n-1;i++){
        int k;
        scanf("%d",&k);
        vector<int> tmp;
        for(int j=0;j<k;j++){
            int x;
            scanf("%d",&x);
            tmp.pb(x);
            e[x].pb(i);
            cnt[x]++;
        }
        v.pb(tmp);
    }
    for(int i = 1;i<=n;i++){
       // if(cnt[i]==1){
      //  printf("%d\n",i);
        fill(vis,vis+205,0);
        fill(ok,ok+205,0);
        fill(cnt,cnt+205,0);
        for(auto it:v){
            for(auto it2:it){
                cnt[it2]++;
            }
        }
        queue<int> q;
        int ok=1;
        for(int j = 1;j<=n;j++){
            if(cnt[j]==1&&j!=i){
                q.push(j);
            }
        }
        if(q.empty())ok=0;
    //    ok[i]=1;
        vector<int> ans;
        int cnt2=0;
        while(!q.empty()){
            // cnt2++;
            int x=q.front();
          //  printf("%d\n",x);
            q.pop();
            if(q.size()){
                ok=0;
                break;
            }
            ans.pb(x);
            for(auto it:e[x]){
                if(!vis[it]){
                   // printf("%d %d %d\n",i,it,v[it].size(),ans.size());
                   // if(v[it].size()!=n-ans.size()+1)ok=0;
                    cnt2++;
                    vis[it]=1;
                    int have=0;
                    for(auto it2:v[it]){
                        if(--cnt[it2]==1&&it2!=i){
                            q.push(it2);
                        }
                        if(it2==i)have=1;
                    }
                    if(have&&v[it].size()!=n-ans.size()+1)ok=0;
                }
            }
        }
        //printf("%d %d\n",i,ok);
        if(!ok||cnt2!=n-1)continue;
        ans.pb(i);
        reverse(ans.begin(),ans.end());
       // printf("!\n");
        for(auto it:ans){
            printf("%d ",it);
        }
        printf("\n");
        break;
        //}
    }
   // printf("?\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/