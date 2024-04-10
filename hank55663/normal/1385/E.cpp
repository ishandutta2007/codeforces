#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
vector<int> v[200005];
int degree[200005];
int ra[200005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i = 1;i<=n;i++){
            v[i].clear();
            degree[i]=0;
        }
        vector<pii> edge;
        for(int i = 1;i<=m;i++){
            int t,x,y;
            scanf("%d %d %d",&t,&x,&y);
            edge.pb(mp(x,y));
            if(t==1){
                v[x].pb(y);
                degree[y]++;
            }
        }
        queue<int> q;
        for(int i = 1;i<=n;i++){
            if(degree[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ra[x]=cnt++;
            for(auto it:v[x]){
                if(--degree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt!=n)printf("NO\n");
        else{
            printf("YES\n");
            for(auto it:edge){
                if(ra[it.x]>ra[it.y]){
                    printf("%d %d\n",it.y,it.x);
                }
                else{
                    printf("%d %d\n",it.x,it.y);
                }
            }
        }
    }
}