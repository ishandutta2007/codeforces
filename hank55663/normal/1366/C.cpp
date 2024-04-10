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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int a[35][35];
        int cnt[70][2];
        MEM(cnt);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                scanf("%d",&a[i][j]);
                cnt[i+j][a[i][j]]++;
            }
        }
        int ans=0;
        for(int i = 0;i<(n+m-1)/2;i++){
            int totone=cnt[n+m-2-i][0],tottwo=cnt[n+m-2-i][1];
            totone+=cnt[i][0];
            tottwo+=cnt[i][1];
            ans+=min(totone,tottwo);
        }
        printf("%d\n",ans);
    }
}
/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/