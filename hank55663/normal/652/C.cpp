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
#define N 262144
vector<int> v[300005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    multiset<int> s;
    int loc[300005];
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        loc[x]=i;
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        x=loc[x];
        y=loc[y];
        if(x>y)swap(x,y);
        v[x+1].pb(y);
        s.insert(y);
       // printf("%d %d\n",x,y);
    }
    LL ans=0;
    s.insert(n+1);
    for(int i = 1;i<=n;i++){
        for(auto it:v[i]){
            s.erase(s.find(it));
        }
        
        ans+=*s.begin()-i;

    }
    printf("%lld\n",ans);
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/