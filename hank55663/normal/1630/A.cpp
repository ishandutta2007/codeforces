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
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(n==4&&k==3){
        printf("-1\n");
        return;
    }
    vector<int> v;
    int loc[66005];
    int vis[66005];
    fill(vis,vis+n,0);
    for(int i = 0;i<n/2;i++){
        loc[i]=v.size();
        v.pb(i);
        loc[n-i-1]=v.size();
        v.pb(n-i-1);
    }
    for(int i = 1;i<n;i+=2){
        int add=0;
        for(int j =0;(1<<j)<n;j++){
            if(!vis[add+(1<<j)+v[i-1]]&&add+(1<<j)+v[i-1]!=v[i]&&(k&(1<<j))){
                add+=(1<<j);
            }
        }
        swap(loc[v[i-1]],loc[v[i-1]+add]);
        swap(v[loc[v[i-1]]],v[loc[v[i-1]+add]]);
        vis[v[i-1]]=1;
        vis[v[i-1]-add]=1;
        vis[v[i]]=1;
        vis[v[loc[v[i-1]-add]^1]]=1;
        k-=add;
    }
    for(int i = 0;i<v.size();i+=2){
        printf("%d %d\n",v[i],v[i+1]);
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567
*/