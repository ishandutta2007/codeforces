




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
#define MXN 150
#define KK 500
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int cnt[2];
    MEM(cnt);
    LL ans1=0,ans2=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<0)swap(cnt[0],cnt[1]),cnt[1]++;
        else cnt[0]++;
        ans1+=cnt[0];
        ans2+=cnt[1];
    }
    printf("%lld %lld\n",ans2,ans1);
    return 0;
}