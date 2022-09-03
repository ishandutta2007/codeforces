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
#define MXN 200005
int from[5005];
vector<int> v[5005];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    pii score[5005];
    int more[5005];
    for(int i = 0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        score[i]=mp(c,i+1);
        more[i+1]=k-a;
        if(k<a){
            printf("-1\n");
            return 0;
        }
        k+=b;
        from[i+1]=i+1;
    }
    for(int i = 0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        from[b]=max(from[b],a);
    }
    for(int i = 1;i<=n;i++){
        v[from[i]].pb(score[i-1].x);
    }
    
    priority_queue<int,vector<int>,greater<int> > pq;
    int ans=0;
    for(int i = 1;i<=n;i++){
        while(pq.size()>more[i]){
            ans-=pq.top();
            pq.pop();
        }
       // printf("%d %d %d\n",i,more[i],ans);
        for(auto it:v[i]){
            pq.push(it);
            ans+=it;
        }
       // printf("%d %d %d\n",i,more[i],ans);
    }
    while(pq.size()>k){
        ans-=pq.top();
        pq.pop();
    }
    printf("%d\n",ans);
}