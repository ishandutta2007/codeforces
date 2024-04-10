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
#define next Next
int main() {
    int q;
    scanf("%d",&q);
    while(q--){
        int n,k;
        scanf("%d %d",&n,&k);
        int a[200005];
        int cnt=0;
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]&1)cnt++;
        }
        if(cnt<k||((cnt-k)&1)!=0){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            for(int i = 0;i<n;i++){
                if(k==1)
                break;
                if(a[i]&1){
                    printf("%d ",i+1);
                    k--;
                }
            }
            printf("%d\n",n);
        }
    }
}