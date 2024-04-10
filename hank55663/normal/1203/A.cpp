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
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        int a[205];
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int ok=0;
        int ook=1;
        for(int i = 0;i<n-1;i++){
            if(a[i]%n+1!=a[i+1])
                ook=0;
        }
        ok|=ook;
        ook=1;
        for(int i = 0;i<n-1;i++){
            if((a[i]%n+n-2)%n+1!=a[i+1]){
                ook=0;
            }
        }
        ok|=ook;
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */