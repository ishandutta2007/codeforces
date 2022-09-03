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
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
int main(){
    int t=1;
    while(t--){
        int n;
        scanf("%d",&n);
        int a[100005];
        a[0]=0;
        for(int i = 1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i = 1;i<=n;i++){
            if(a[i]<a[i-1]){
                printf("-1\n");
                return 0;
            }
        }
        
        int b[100005];
        MEMS(b);
        for(int i = 1;i<=n;i++){
            if(a[i]!=a[i-1])b[i]=a[i-1];
        }
        
        set<int> s;
        int now=1e6;
        for(int i=n;i>=1;i--){
            while(now>a[i])s.insert(now),now--;
            if(now==a[i])now--;
            if(b[i]==-1){
                b[i]=*s.begin();
                s.erase(s.begin());
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
    }
}