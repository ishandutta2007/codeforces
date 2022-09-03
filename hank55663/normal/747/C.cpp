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
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    priority_queue<int,vector<int>,greater<int> >pq;
    priority_queue<pii,vector<pii>,greater<pii> > pq2;
    for(int i = 1;i<=n;i++){
        pq.push(i);
    }
    while(q--){
        int t,k,d;
        scanf("%d %d %d",&t,&k,&d);
        while(!pq2.empty()&&pq2.top().x<=t){
            pq.push(pq2.top().y);
            pq2.pop();
        }
        if(pq.size()>=k){
            int ans=0;
            for(int i=0;i<k;i++){
                ans+=pq.top();
                pq2.push(mp(t+d,pq.top()));
                pq.pop();
            }
            printf("%d\n",ans);
        }
        else{
            printf("-1\n");
        }
    }
}