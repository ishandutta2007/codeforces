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
#define hash Hash
int main(){
    int n;
    scanf("%d",&n);
    int a[300005];
    int Max=0,Min=1e9;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        a[n+i]=a[i];
        a[2*n+i]=a[i];
        Max=max(Max,a[i]);
        Min=min(Min,a[i]);
    }
    if(Min*2>=Max){
        for(int i = 0;i<n;i++)
            printf("-1 ");
        printf("\n");
        return 0;
    }
    else{
        deque<pii> q;
        int now=0;
        
        for(int i = 0;i<n;i++){
          //  printf("%d\n",i);
            while(q.empty()||q.front().x<=q.back().x*2){
                while(!q.empty()&&q.back().x<a[now]){
                    q.pop_back();
                }
                q.push_back(mp(a[now],now));
                now++;
            }
            printf("%d ",now-i-1);
            if(q.front().y==i){
                q.pop_front();
            }
        }
        printf("\n");
    }
}