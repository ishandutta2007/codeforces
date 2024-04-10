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
#define MXN 10005
#define less Less
int degree[1000005];
pii p[1000005];
vector<int> v[1000005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>y)swap(x,y);
        p[i]=mp(x,y);
        v[x].pb(i);
        degree[x]++;
        degree[y]++;
    }
    vector<int> ans;
    for(int i = 1;i<=n;i++){
       degree[i]/=2; 
    }
    for(int i = 1;i<=n;i++){
        vector<pii> tmp;
        for(auto it:v[i]){
            tmp.pb(mp(degree[p[it].y],it));
        }
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        int j;
        for(j = 0;j<degree[i]&&j<tmp.size();j++){
            if(degree[p[tmp[j].y].y])
            degree[p[tmp[j].y].y]--;
            else{
                break;
            }
        }
        for(;j<tmp.size();j++){
            ans.pb(tmp[j].y);
        }
    }
    printf("%d\n",ans.size());
    for(auto it:ans)
        printf("%d %d\n",p[it].x,p[it].y);
}