
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
#define KK 500
#define N 100005
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    set<int> s;
    queue<pii> q;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        s.insert(x);
        q.push(mp(x+1,1));
        q.push(mp(x-1,-1));
    }
    LL ans=0;
    vector<int> res;
    for(int i = 0;i<m;i++){
        pii p=q.front();
        q.pop();
        while(s.find(p.x)!=s.end()){
            p=q.front();
            q.pop();
        }        
        res.pb(p.x);
        s.insert(p.x);
        ans+=abs(p.y);
        if(p.y>0){
            p.y++;
            p.x++;
            q.push(p);
        }
        else{
            p.y--;
            p.x--;
            q.push(p);
        }
    }
    printf("%lld\n",ans);
    for(auto it:res)
    printf("%d ",it);
    printf("\n");
}
/*
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/