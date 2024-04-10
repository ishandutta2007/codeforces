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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    vector<pii> pos,neg;
    for(int i = 0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(b>=0)
        pos.pb(mp(a,b));
        else
        neg.pb(mp(a,b));
    }
    sort(pos.begin(),pos.end());
    int ans=0;
    for(auto it:pos){
        if(r>=it.x){
            r+=it.y;
            ans++;
        }
    }
    for(auto &it:neg){
        it.x+=it.y;
        it.x=max(it.x,0);
    }
    sort(neg.begin(),neg.end());
    reverse(neg.begin(),neg.end());
    priority_queue<int,vector<int>,greater<int> > pq;
    for(auto &it:neg){
        r+=it.y;
        pq.push(it.y);
        if(r<it.x){
            r-=pq.top();
            pq.pop();
        }
    }
    ans+=pq.size();
    if(ans==n){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
   // printf("%d\n",ans);
    return 0;
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */