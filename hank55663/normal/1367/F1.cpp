#include<bits/stdc++.h>
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
using namespace std;
vector<int> v[200005];
int ans[200005];
void solve(){
    map<int,int> m;
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]];
    }
    int cnt=0;
    for(auto &it:m){
        it.y=++cnt;
    }
    for(int i = 1;i<=cnt+5;i++)v[i].clear();
    for(int i = 0;i<n;i++){
        v[m[a[i]]].pb(i);
    }
    int now=1;
    int lastans=0;
    for(int i = 1;i<=cnt;i++){
        if(now>i){
            ans[i]=lastans;
        }
        else{
            now++;
            int tot=0;
            tot+=v[i].size();
            while(now<=cnt&&v[now][0]>v[now-1].back())tot+=v[now].size(),now++;
            tot+=v[now].end()-lower_bound(v[now].begin(),v[now].end(),v[now-1].back());
            lastans=tot;
            ans[i]=tot;
        }
        lastans-=v[i].size();
      //  printf("%d\n",ans[i]);
    }
    int res=v[cnt].size();
    for(int i = 1;i<cnt;i++){
        for(int j = 0;j<v[i].size();j++){
            if(v[i][j]<v[i+1][0]){
                res=max(res,j+1+ans[i+1]);
             //   printf("%d %d %d\n",i,j+1,ans[i+1]);
            }
            else{
                res=max(res,j+1+(int)(v[i+1].end()-lower_bound(v[i+1].begin(),v[i+1].end(),v[i][j])));
            //    printf("%d %d %d\n",i,j+1,(int)(v[i+1].end()-lower_bound(v[i+1].begin(),v[i+1].end(),v[i][j])));
            }
        }
    }
    printf("%d\n",n-res);
}
int main(){
    int t=1;
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