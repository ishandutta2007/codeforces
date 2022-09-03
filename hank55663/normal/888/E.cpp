#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[50];
    vector<int> v[2];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        v[i&1].pb(a[i]);
    }
    vector<LL> val[2];
    for(int i = 0;i<2;i++){
        for(int  j=0;j<(1<<v[i].size());j++){
            LL sum=0;
            for(int k=0;k<v[i].size();k++){
                if(j&(1<<k)){
                    sum+=v[i][k];
                }
            }
            val[i].pb(sum%m);
        }
        val[i].pb(0);
        sort(val[i].begin(),val[i].end());
    }
    LL ans=0;
    for(auto it:val[0]){
        LL val2=it+val[1].back();
        LL val1=it+*(lower_bound(val[1].begin(),val[1].end(),m-it)-1);
        ans=max(val1,ans);
        ans=max(val2%m,ans);
    }
    printf("%lld\n",ans);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/