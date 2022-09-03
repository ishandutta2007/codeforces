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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int main(){ 
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",upper_bound(a,a+n,x)-a);
    }
}
/**/