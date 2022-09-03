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
#define N 200005
#define rank Rank
#define index Index
char c[1005][1005];
pii tmp[1005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i =1;i<=n;i++)
        scanf("%s",c[i]+1);
    vector<int> res;
    for(int j=1;j<=m;j++){
        vector<pair<char,int> > v;
        for(int i=1;i<=n;i++){
            if(v.empty()||v.back().x!=c[i][j])v.pb(mp(c[i][j],1));
            else v.back().y++;
        }
        int less=0,now=-1;
        for(int i = 1;i<=n;i++){
          //  printf("%d %d %d %d\n",i,j-1,tmp[i].x,tmp[i].y);
            if(less==0){
                now++;
                less=v[now].y;
            }
            if(now<v.size()-2&&v[now+1].y==less&&v[now+2].y>=less){
                if(tmp[i].x==less*3&&c[i][j-1]==c[i][j]&&c[i+less][j-1]==c[i+less][j]
                &&c[i+less*2][j-1]==c[i+less*2][j]){
                    tmp[i].y++;
                }
                else{
                    res.pb(tmp[i].y);
                    tmp[i]=mp(less*3,1);
                }
            }
            else{
                res.pb(tmp[i].y);
                tmp[i]=mp(0,0);
            }
            less--;
        }
    }
    for(int i = 1;i<=n;i++){
        res.pb(tmp[i].y);
      //  printf("%d %d %d %d\n",i,m,tmp[i].x,tmp[i].y);
    }
    LL sum=0;
    for(auto it:res){
        //printf("%d\n",it);
        sum+=it*(it+1)/2;
    }
    printf("%lld\n",sum);
}