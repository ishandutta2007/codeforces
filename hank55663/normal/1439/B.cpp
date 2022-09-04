#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int degree[100005];
vector<int> v[100005];
unordered_set<int> s[100005];
int vis[100005];
int vis2[100005];
int ok[100005];
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1;i<=n;i++){
        v[i].clear();
        degree[i]=0;
        vis[i]=0;
        ok[i]=0;
        vis2[i]=0;
        s[i].clear();
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        degree[x]++;
        degree[y]++;
        s[x].insert(y);
        s[y].insert(x);
    }
    if(k>=500){
        printf("-1\n");
        return;
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(degree[i]<=k-1){
            q.push(i);
            vis[i]=1;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(degree[x]==k-1){
            for(auto it:v[x]){
                if(!vis2[it])
                    ok[it]=1;
            }
            ok[x]=1;
            int ook=1;
            if(k>=200){
                for(auto it:v[x]){
                    if(!vis2[it])
                    for(auto it2:v[it]){
                        if(ok[it2])ok[it2]++;
                    }
                    ok[it]++;
                }
                for(auto it:v[x]){
                    if(!vis2[it]&&ok[it]!=k){
                        ook=0;
                    }
                }
                ok[x]=0;
                for(auto it:v[x]){
                    ok[it]=0;
                }
            }
            else{
                vector<int> tmp;
                for(auto it:v[x]){
                    if(!vis2[it]){
                        tmp.pb(it);
                    }
                }
                for(int i = 0;i<tmp.size();i++){
                    for(int j =i+1;j<tmp.size();j++){
                        if(s[tmp[i]].find(tmp[j])==s[tmp[i]].end())ook=0;
                    }
                }
            }
            if(ook){
                printf("2\n");
                printf("%d ",x);
                for(auto it:v[x]){
                    if(!vis2[it])
                    printf("%d ",it);
                }
                printf("\n");
                return;
            }
        }
        vis2[x]=1;
        for(auto it:v[x]){
            if(--degree[it]<=k-1&&!vis[it]){
                q.push(it);
                s[it].erase(x);
                s[x].erase(it);
                vis[it]=1;
            }
        }
    }
    vector<int> v;
    for(int i = 1;i<=n;i++){
        if(!vis[i])v.pb(i);
    }
    if(v.size()){
        printf("1 %d\n",v.size());
        for(auto it:v){
            printf("%d ",it);
        }
        printf("\n");
    }
    else{
        printf("-1\n");
    }
}

int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}