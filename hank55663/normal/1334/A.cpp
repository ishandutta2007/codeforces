#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        pii p[105];
        for(int i = 0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            p[i]=mp(x,y);
        }
        int ok=1;
        if(p[0].y>p[0].x)ok=0;
        for(int i = 1;i<n;i++)
        if(p[i].x<p[i-1].x||p[i].y<p[i-1].y||p[i].x-p[i-1].x+p[i-1].y<p[i].y||p[i].y>p[i].x){
            ok=0;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}
/*

*/