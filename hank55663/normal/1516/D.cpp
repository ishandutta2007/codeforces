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
int Next[20][100005];
vector<int> fac[100005];
int last[100005];
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    int a[100005];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=100000;i++)last[i]=n;
    Next[0][n]=n;
    int r=n;
    for(int i = n-1;i>=0;i--){
        for(auto it:fac[a[i]]){
            r=min(r,last[it]);
            last[it]=i;
        }
        Next[0][i]=r;
       // printf("%d %d\n",i,r);
    }
    for(int i = 1;i<20;i++){
        for(int j = 0;j<=n;j++){
            Next[i][j]=Next[i-1][Next[i-1][j]];
        }
    }
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        l--,r--;
        int ans=0;
        for(int i = 19;i>=0;i--){
            if(Next[i][l]<=r){
                ans+=(1<<i);
                l=Next[i][l];
            }
        }
        printf("%d\n",ans+1);
    }
}
int main(){
    for(int i = 2;i<=100000;i++){
        if(fac[i].empty())
            for(int j=i;j<=100000;j+=i){
                fac[j].pb(i);
            }
    }
    int t=1;00000;
 //   scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/