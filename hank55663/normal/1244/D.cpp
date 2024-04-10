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
int cost[3][100005];
vector<int> v[100005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<3;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    int end=0;
    for(int i = 1;i<=n;i++){
        if(v[i].size()>=3){
            printf("-1\n");
            return 0;
        }
        if(v[i].size()==1){
            end=i;
        }
    }
    vector<int> seq;
    seq.pb(end);
    end=v[end][0];
    seq.pb(end);
    for(int i = 3;i<=n;i++){
        for(auto it:v[end]){
            if(it!=seq[seq.size()-2]){
                end=it;
                seq.pb(end);
                break;
            }
        }
    }
 //   printf("%d\n",seq.size());
    int a[3]={0,1,2};
    int res[3];
    LL ans=1e18;
    do{
        LL sum=0;
        for(int i = 0;i<seq.size();i++){
          sum+=cost[a[i%3]][seq[i]];
         //   printf("%d",cost[a[i%3]][seq[i]]);
        }
      //  printf("\n");
        ans=min(ans,sum);
        if(ans==sum){
            for(int j=0;j<3;j++)
            res[j]=a[j];
        }
    }while(next_permutation(a,a+3));
    printf("%lld\n",ans);
    int col[100005];
    for(int i = 0;i<seq.size();i++){
        col[seq[i]]=res[i%3];
    }
    for(int i=1;i<=n;i++)
    printf("%d ",col[i]+1);
    printf("\n");
}
/*
3 5 12
..X..
R..?.
LX...
100 100 100 100 8
1000000000000
100000000000000000
100000
1
*/