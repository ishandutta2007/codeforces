#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int ori=n;
    vector<int> v;
    for(int i = 2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            v.pb(i);
        }
    }
        if(n!=1)v.pb(n);
    n=ori;
    vector<int> factor;
    for(int i = 2;i*i<=n;i++){
        if(n%i==0){
            factor.pb(i);
            if(i*i!=n){
                factor.pb(n/i);
            }
        }
    }
    factor.pb(n);

    if(v.size()==2){
        if(v[0]*v[1]==n){
            printf("%d %d %d\n",v[0],v[1],n);
            printf("1\n");
            return;
        }
    }
    if(v.size()==1){
        for(auto it:factor)printf("%d ",it);
        printf("\n0\n");
        return ;
    }
    vector<int> g[20];
    for(auto it:factor){
        for(int j = 0;j<v.size();j++){
            if(it%v[j]==0){
                g[j].pb(it);
                break;
            }
        }
    }
    for(int i =1;i<v.size()-1;i++){
        for(int j =0;j<g[i].size();j++){
            if(g[i][j]%v[i+1]==0){
                swap(g[i][j],g[i].back());
                break;
            }
        }
    }
    sort(g[0].begin(),g[0].end());
    for(int j = 0;j<g[0].size();j++){
        if(g[0][j]%v.back()==0)swap(g[0][0],g[0][j]);
        if(g[0][j]%v[1]==0)swap(g[0].back(),g[0][j]);
    }
    for(int i = 0;i<v.size();i++){
        for(auto it:g[i]){
            printf("%d ",it);
        }
    }
    printf("\n0\n");
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