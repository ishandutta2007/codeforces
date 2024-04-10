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
#define MXN 1500
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            pq.push(x);
        }
        int ok=0;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            if(x==2048){
                printf("YES\n");
                ok=1;
                break;
            }
            if(pq.empty())break;
            int y=pq.top();
            pq.pop();
            if(x==y){
                pq.push(x+y);
            }
            else{
                pq.push(y);
            }
        }
        if(!ok){
            printf("NO\n");
        }
    }
    return 0;
}
/*
5 5
 _ _ _ _ _
|_ _  |_  |
|  _| |  _|
| |_   _| |
|    _ _  |
|_|_ _ _|_|

*/