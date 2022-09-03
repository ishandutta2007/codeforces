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
#define MXN 300000
#define N 100005
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v[100005];
    int a[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[a[i]].pb(x);
    }
    int cnt=0;
    vector<int> tmp;
    for(int i = 1;i<=k;i++){
        if(v[i].empty())cnt++;
        else{
            sort(v[i].begin(),v[i].end());
            for(int j=0;j<v[i].size()-1;j++)
                tmp.pb(v[i][j]);
        }
    }
    sort(tmp.begin(),tmp.end());
    LL ans=0;
    for(int i = 0;i<cnt;i++)
        ans+=tmp[i];
    printf("%lld\n",ans);
}