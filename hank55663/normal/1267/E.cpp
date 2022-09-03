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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[105][105];
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    int ans=1e9;
    vector<int> res;
    for(int i = 0;i<n-1;i++){
        vector<pii> dif;
        int sum=0;
        for(int j=0;j<m;j++){
            dif.pb(mp(a[j][i]-a[j][n-1],j+1));
            sum+=a[j][i]-a[j][n-1];
        }
        sort(dif.begin(),dif.end());
        dif.pb(mp(0,0));
        vector<int> tmp;
        for(int i=0;i<dif.size();i++){
            if(sum>=0)break;
            tmp.pb(dif[i].y);
            sum-=dif[i].x;
        }
        if(tmp.size()<ans){
            ans=tmp.size();
            res=tmp;
        }
    }
    printf("%d\n",ans);
    for(auto it:res)
    printf("%d ",it);
    printf("\n");
}
/*
2 -2000000000 2 -20000000000 1 1
*/