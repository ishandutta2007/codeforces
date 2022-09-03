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
#define MXN 300005
#define index Index
int a[1000005];
int main(){
    int n;
    scanf("%d",&n);
    int dis[105][105];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dis[i][j]=1e9;
            char c;
            scanf(" %c",&c);
            if(c=='1')
            dis[i][j]=1;
            if(i==j){
                dis[i][j]=0;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    vector<int> ans;
    int m;
    scanf("%d",&m);

    for(int i = 0;i<m;i++){
        scanf("%d",&a[i]);
    }
    ans.pb(a[0]);
    int last=0;
    for(int i = 1;i<m;i++){
        if(dis[a[last]][a[i]]!=i-last){
            ans.pb(a[i-1]);
            last=i-1;
         //   printf("%d %d %d\n",i-1,dis[a[last]][a[i]],last-i);
        }
       // printf("%d\n",a[i]);
    }
    ans.pb(a[m-1]);
    printf("%d\n",ans.size());
    for(auto it:ans)
    printf("%d ",it);
    printf("\n");
}

/*
7
A B son of C
A C son of D
A D son of B
A E son of B
A F son of C
A G son of D
A H son of E
*/