#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
int main(){
    int n;
    scanf("%d",&n);
    int degree[100005];
    MEM(degree);
    for(int i = 0;i<n-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        degree[x]++;
        degree[y]++;
    }
    int ok=1;
    for(int i = 1;i<=n;i++){
        if(degree[i]==2){
            ok=0;
        }
    }
    if(ok)printf("YES\n");
    else printf("NO\n");
}
/*
1 
2 6 
3 5 
4
*/