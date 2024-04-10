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
#define MXN 205
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int p[105];
    for(int i = 1;i<=k;i++){
        int x;
        scanf("%d",&x);
        p[x]=i;
    }
    int ans=0;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            ans+=p[x];
            for(int a=1;a<=k;a++){
                if(p[a]<p[x])p[a]++;
            }
            p[x]=1;
        }
    }
    printf("%d\n",ans);
}
/*
0
10
20
30
40

4+3+3+4+3+2+2+1
13:00
11:

11:24
11:48
12:12
12:36
13:00
13:24
13:48
14:12
14:36
*/