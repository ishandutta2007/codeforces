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
vector<vector<int> > v;
int val[45];
int tmp[15][45];
//unordered_set<LL> s[11];
bool dfs(int i,int k,int n){
    if(i==k){
        for(int j = 1;j<=n;j++){
            if(val[j]==-1)return false;
        }
        for(int j=1;j<n;j++){
            if(val[j]>val[j+1])return false;
        }
        return true;
    }
    //int tmp[45];
    for(auto j:v[i]){
        tmp[i][j]=val[j];
    }
   // if(s[i].find(sum)!=s[i].end())return true;

    int cnt=0,tot=0;
    for(auto it:v[i]){
        if(tmp[i][it]==-1)tot++;
        if(tmp[i][it]==0)cnt++;
    }
    for(int a = cnt;a<=cnt+tot;a++){
        for(int j = 0;j<a;j++){
            val[v[i][j]]=0;
        }
        for(int j = a;j<v[i].size();j++){
            val[v[i][j]]=1;
        }
        if(!dfs(i+1,k,n))return false;
        for(auto it:v[i])val[it]=tmp[i][it];
    }
    //    s[i].insert(sum);
    return true;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(n==1){
        printf("ACCEPTED\n");
        return;
    }
    queue<vector<pii> > q,q2;
    q.push(vector<pii>());
    int vis[45];
    fill(vis,vis+n+1,0);
    int xx=0;
    for(int i=0;i<k;i++){
        int a=4*i+4;
        scanf("%d",&a);
        vector<int> tmp;
        if(a==n){
            printf("ACCEPTED\n");
            return;
        }
        int tot=0;
        int in[45];
        fill(in,in+n+1,0);
        for(int j = 0;j<a;j++){
            int x=j+1;
            //xx++;
            scanf("%d",&x);
            tmp.pb(x);
            if(!vis[x])tot++;
            vis[x]=1;
            in[x]=1;
        }
        v.pb(tmp);
    }
    MEMS(val);
    if(!dfs(0,k,n))printf("REJECTED\n");
    else printf("ACCEPTED\n");
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/