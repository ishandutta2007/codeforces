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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int a[105];
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        int ok[105];
        MEM(ok);
        for(int i = 0;i<m;i++){
            int x;
            scanf("%d",&x);
            x--;
            ok[x]=1;
        }
        int last=0;
        for(int i = 0;i<n;i++){
            if(ok[i]==0){
                sort(a+last,a+i+1),last=i+1;
                
            }
        }
        int ook=1;
        for(int i = 0;i<n-1;i++){
            if(a[i]>a[i+1])ook=0;
        }
        if(ook)printf("YES\n");
        else printf("NO\n");
    }
}