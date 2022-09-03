#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    pii p[1005];
    int ans[1005];
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    sort(p,p+n);
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    int now=0;
    for(int i = 1;i<=n;i++){
        while(now<n&&p[now].x<=i){
            pq.push(mp(p[now].y,now));
            now++;
        }
        ans[pq.top().y]=i;
        pq.pop();
    }
    for(int i = 0;i<n;i++){
        printf("%d %d %d\n",p[i].x,p[i].y,ans[i]);
    }
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/