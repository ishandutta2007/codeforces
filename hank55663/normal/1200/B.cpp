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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int h[105];
        for(int i = 0;i<n;i++){
            scanf("%d",&h[i]);
        }
        int ok=1;
        for(int i = 0;i<n-1;i++){
            m+=(h[i]-(max(h[i+1]-k,0)));
            if(m<0){
                ok=0;
            }
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}