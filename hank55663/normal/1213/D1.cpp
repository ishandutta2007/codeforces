#include<bits/stdc++.h>
using namespace std;
#pragma optimizer(-Ofast)
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
#define rank Rank
#define MXN 15000
vector<int> v[200005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        for(int t=0;x;t++){
            v[x].pb(t);
            x/=2;
        }
    }
    int ans=1e9;
    for(int i = 0;i<=200000;i++){
        sort(v[i].begin(),v[i].end());
        if(v[i].size()>=k){
            int sum=0;
            for(int j=0;j<k;j++)
            sum+=v[i][j];
            ans=min(ans,sum);
        }
    }
    printf("%d\n",ans);
    return 0;
}