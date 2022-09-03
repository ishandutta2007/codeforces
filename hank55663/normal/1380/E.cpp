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
set<int> s[200005];
int loc[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int ans=0;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        s[x].insert(i);
        loc[i]=x;
        if(loc[i]!=loc[i-1])ans++;
    }
    printf("%d\n",ans-1);
    m--;
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(s[a].size()>s[b].size())swap(s[a],s[b]);
        for(auto it:s[a]){
            //if(s[a].find(it-1)!=s[a].end())ans++;
          //  if(s[a].find(it+1)!=s[a].end())ans++;
          //  else ans--;
            if(s[b].find(it-1)!=s[b].end())ans--;
            if(s[b].find(it+1)!=s[b].end())ans--;
          //  if(s[b].find(it+1)==s[b].end()&&s[b].find(it-1)==s[b].end())ans++;
          //  s[b].insert(it);
             // printf("!%d %d\n",ans-1,it);
        }
        for(auto it:s[a]){
            s[b].insert(it);
        }
        swap(s[a],s[b]);
        printf("%d\n",ans-1);
    }

}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}