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
int S[100005];
void add(int x,int k){
    for(int i = x;i<100005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
vector<int> vis[100005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    int val[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        val[i]=0;
    }
    for(int i = 1;i<=n;i++){
        val[i]=i-1-query(a[i]);
        val[i]&=1;
        add(a[i],1);
    }
    for(int i = 1;i<=n;i++)add(a[i],-1);
    for(int i = n;i>=1;i--){
        val[i]+=query(a[i]-1);
        val[i]&=1;
        add(a[i],1);
    }
    for(int i = 1;i<=n;i++)add(a[i],-1);
    int cnt=0;
    for(int i = 1;i<=n;i++){
        /*if(val[i]){
            if(vis[a[i]])cnt--,vis[a[i]]=0;
            else cnt++,vis[a[i]]++;
        }*/
        if(val[i]==1){
            if(vis[a[i]].empty()||vis[a[i]].back()!=1){
                cnt++;
                vis[a[i]].pb(val[i]);
            }
            else{
                cnt--;
                vis[a[i]].pop_back();
            }
        }
        else{
            if(vis[a[i]].empty()||vis[a[i]].back()==1)
            vis[a[i]].pb(val[i]);
            else{
                vis[a[i]].pop_back();
            }
        }
    }
    
    if(cnt)printf("No\n");
    else printf("Yes\n");
    for(int i =1;i<=n;i++)vis[a[i]].clear();
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}