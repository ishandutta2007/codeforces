#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
#define MXN 200005
pii loc[4000005];
    int a[2005][2005];
    int ans[2005][2005];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&a[i][j]);
            loc[a[i][j]]=mp(i,j);
            ans[i][j]=0;
        }
    }
    set<int> x,y;
    pii p=loc[n*n];
    x.insert(p.x+p.y);
    y.insert(p.x-p.y);
    ans[p.x][p.y]=1;
    for(int i = n*n-1;i>=1;i--){
        pii p=loc[i];
        int xx=p.x+p.y,yy=p.x-p.y;
        if(abs(xx-*x.begin())<=k&&abs(*x.rbegin()-xx)<=k&&abs(yy-*y.begin())<=k&&abs(yy-*y.rbegin())<=k){
            ans[p.x][p.y]=1;
            x.insert(xx);
            y.insert(yy);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(ans[i][j])printf("M");
            else printf("G");
        }
        printf("\n");
    }
}  
 
 
int main(){
    int t=1;0000;
 // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
 
*/