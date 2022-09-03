#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int mod=998244353;
vector<int> v[400005];
vector<int> onsale[400005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int k[200005];
    for(int i = 1 ;i<=n;i++){
        scanf("%d",&k[i]);
    }
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[y].pb(x);
    }
    for(int i = 1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
        v[i].pb(1e9);
    }
    int Max= 4e5+2,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        for(int i = 1 ; i<=mid ; i++){
            onsale[i].clear();
        }
        int need[200005];
        int tot=0;
        for(int i = 1 ; i<=n ; i++){
            need[i]=k[i];
            tot+=k[i];
            if(v[i][0]>mid){
                continue;
            }
            int x=*(upper_bound(v[i].begin(),v[i].end(),mid)-1);
            onsale[x].pb(i);
        }
        int now=0;
        for(int i = 1;i<=mid;i++){
            now++;
            for(auto it:onsale[i]){
                while(need[it]&&now){
                    need[it]--;
                    now--;
                    tot--;
                }
            }
        }
        if(now>=tot*2){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    printf("%d\n",Max);
}