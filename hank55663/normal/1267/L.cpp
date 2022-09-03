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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
int main(){
    int n,l,k;
    scanf("%d %d %d",&n,&l,&k);
    char c[1000005];
    scanf("%s",c);
    sort(c,c+n*l);
    char ans[1005][1005];
    MEM(ans);
    int now=0;
    for(int i = 1;i<=l;i++){
        for(int j =0;j<k;j++){
            if(ans[j][i-1]==ans[k-1][i-1]){
                ans[j][i]=c[now++];
            }
        }
    }
    //printf("%d\n")
    for(int i=1;i<=l;i++){
        for(int j=0;j<n;j++){
            if(ans[j][i]==0)ans[j][i]=c[now++];
        }
    }
    for(int i = 0;i<n;i++)
    printf("%s\n",ans[i]+1);
}
/*
2 -2000000000 2 -20000000000 1 1
*/