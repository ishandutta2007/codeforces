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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    map<int,vector<int> > computer;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        computer[x].pb(i);
    }
    vector<pii> s;
    for(int i=0;i<m;i++){
        int a;
        scanf("%d",&a);
        s.pb(mp(a,i+1));
    }
    int sum=0,ans=0;
    int match[200005];
    MEM(match);
    int use[200005];
    MEM(use);
    while(1){
        int ok=0;
        vector<pii> tmp;
        for(auto it:s){
            if(computer.find(it.x)!=computer.end()){
                int x=computer[it.x].back();
                computer[it.x].pop_back();
                if(computer[it.x].empty())
                    computer.erase(it.x);
                match[x]=it.y;
                ans++;
                sum+=use[it.y];
                ok=1;
            }
            else{
                tmp.pb(mp((it.x+1)/2,it.y));
                use[it.y]++;
            }
            if(it.x!=1)ok=1;
        }
        swap(tmp,s);
        if(!ok)
        break;
    }
    for(auto it:s){
        use[it.y]=0;
    }
    printf("%d %d\n",ans,sum);
    for(int i = 1;i<=m;i++)
    printf("%d ",use[i]);
    printf("\n");
    for(int i =0;i<n;i++)
    printf("%d ",match[i]);
    printf("\n");
    return 0;
}