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
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005

void solve(){
    int n;
    scanf("%d",&n);
    map<int,int> m;
    int ans=1e9;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(m.find(x)!=m.end()){
            ans=min(ans,i-m[x]+1);
        }
        m[x]=i;
    }
    if(ans==1e9)ans=-1;
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       solve();
    }
}
/*
5 4
8 1 0 3 0
0 0 1 3 8
1
*/