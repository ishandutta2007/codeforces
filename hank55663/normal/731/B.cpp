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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int main() {
    int n;
    scanf("%d",&n);
    int a[200005];
    int has[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i])has[i]=1;
        else has[i]=0;
        a[i]%=2;
    }
    int need=0;;
    for(int i = 0;i<n;i++){
        if(a[i]==1){
            need^=1;
        }
        else{
            if(need&&!has[i]){
                printf("NO\n");
                return 0;
            }
        }
    }
    if(need)printf("NO\n");
    else printf("YES\n");
    return 0;
}