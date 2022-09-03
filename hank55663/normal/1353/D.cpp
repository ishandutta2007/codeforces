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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        priority_queue<pair<int,pii> > pq;
        int ans[200005];
        pq.push(mp(n,mp(1,n)));
        int cnt=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int len=p.x;
            int l=p.y.x;
            int r=p.y.y;
            int pos;
            if((r-l+1)%2){
                pos=(r+l)/2;
                ans[(r+l)/2]=++cnt;
            }
            else{
                pos=(r+l+1)/2;
                ans[(r+l+1)/2]=++cnt;
            }
            if(l<=pos-1){
                pq.push(mp(pos-l,mp(l,pos-1)));
            }
            if(r>=pos+1){
                pq.push(mp(r-pos,mp(pos+1,r)));
            }
        }
        reverse(ans+1,ans+n+1);
        for(int i = 1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }

}

/*
C[i][j]=C[i>>1][j]
1000

1001
0000
0001
1000
1001
*/