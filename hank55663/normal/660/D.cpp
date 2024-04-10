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
    int n;
    scanf("%d",&n);
    unordered_map<LL,int> m;
    pii p[2005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                m[(p[j].x-p[i].x)*4000000000ll+p[j].y-p[i].y]++;
            }
        }
    }
    LL ans=0;
    for(auto it:m){
        ans+=(LL)it.y*(it.y-1)/2;
    }
    printf("%lld\n",ans/4);
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