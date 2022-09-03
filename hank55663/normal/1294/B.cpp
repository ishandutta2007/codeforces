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
#define ld long double
void solve(){
    int n;
    scanf("%d",&n);
    pii p[1005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    sort(p,p+n);
    for(int i = 0;i<n-1;i++){
        if(p[i].y>p[i+1].y){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    int x=0,y=0;
    for(int i  =0;i<n;i++){
        while(p[i].x>x)printf("R"),x++;
        while(p[i].y>y)printf("U"),y++;
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}