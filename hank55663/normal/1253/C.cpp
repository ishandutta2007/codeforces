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
#define MXN 300000
#define N 100005
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    LL a[200005];
    for(int i =0;i<n;i++)
    scanf("%lld",&a[i]);
    sort(a,a+n);
    LL ans=0;
    for(int i = m;i<n;i++){
        a[i]+=a[i-m];
    }
    for(int i = 0;i<n;i++){
        ans+=a[i];
        printf("%lld ",ans);
    }
}