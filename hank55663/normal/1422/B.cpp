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
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> v[105][105];
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            int x;
            scanf("%d",&x);
            v[min(i,n-i-1)][min(j,m-j-1)].pb(x);
        }
    }
    LL ans=0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(v[i][j].size()){
                sort(v[i][j].begin(),v[i][j].end());
                int mid=v[i][j][v[i][j].size()/2];
                for(auto it:v[i][j])ans+=abs(mid-it);
            }
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/