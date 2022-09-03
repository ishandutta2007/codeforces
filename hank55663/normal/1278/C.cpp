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
#define rank Rank
#define KK 500
#define N 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[200005];
        for(int i=1;i<=2*n;i++){
            scanf("%d",&a[i]);
            if(a[i]==2)a[i]=-1;
        }
        map<int,int> m;
        int now=0;
        m[now]=0;
        int cnt=0;
        for(int i = 2*n;i>n;i--){
            cnt++;
            now+=a[i];
            m[now]=cnt;
        }
        int ans=0;
        now=0;
        ans=2*n-m[0];
        for(int i = 1;i<=n;i++){
            now+=a[i];
            if(m.find(-now)!=m.end()){
                ans=min(ans,2*n-m[-now]-i);
            }
        }
        printf("%d\n",ans);
    }
}