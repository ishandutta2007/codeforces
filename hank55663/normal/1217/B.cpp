#include<bits/stdc++.h>
using namespace std;
#pragma optimizer(-Ofast)
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
#define rank Rank
#define MXN 15000

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d %d",&n,&x);
        multiset<int> s;
        pii p[105];
        for(int i = 0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            s.insert(y-x);
            p[i]=mp(x,y);
        }
        //s.insert(-1);
        int ans=2e9;
        for(int i = 0 ;i<n;i++){
          //  s.erase(s.find(p[i].y-p[i].x));
            int now=x;
            int a=-*s.begin();
            if(now<=p[i].x)
            ans=1;
            else if(a>=1){
                ans=min(ans,(now-p[i].x+a-1)/a+1);
            }
            //s.insert(p[i].y-p[i].x);
        }
        if(ans==2e9)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}