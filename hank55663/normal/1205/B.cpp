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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
#define XXX 2520
/*int main(){
    int n;
    scanf("%d",&n);
    if(n%2==0){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        vector<int> v;
        for(int i = 1;i<2*n;i+=2){
            v.pb(i);
        }
        for(int i = 0;i<v.size();i++){
            if(i&1)
            printf("%d ",v[i]+1);
            else
            printf("%d ",v[i]);
        }
        for(int i = 0;i<v.size();i++){
            if(i&1)
            printf("%d ",v[i]);
            else
            printf("%d ",v[i]+1);
        }
    }
}*/
vector<int> v[300];
int main(){
    int n;
    scanf("%d",&n);
    LL a[100005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]==0){
            i--;
            n--;
        }
    }
    for(int i = 0;i<64;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]&(1ll<<i)){
                cnt++;
            }
        }
        if(cnt>=3){
            printf("3\n");
            return 0;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(a[i]&a[j]){
                v[i].pb(j);
                v[j].pb(i);
            }
        }
    }
    int ans=1e9;
    for(int i = 0;i<n;i++){
        int vis[405];
        int last[405];
        queue<int> q;
        q.push(i);
        MEMS(vis);
        MEMS(last);
        vis[i]=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto it:v[x]){
                if(it!=last[x]){
                    if(vis[it]==-1){
                        vis[it]=vis[x]+1;
                        last[it]=x;
                        q.push(it);
                    }
                    else{
                        ans=min(ans,vis[it]+vis[x]+1);
                    }
                }
            }
        }
    }
    if(ans==1e9)
    ans=-1;
    printf("%d\n",ans);
}
/*
1 4  2  3

*/