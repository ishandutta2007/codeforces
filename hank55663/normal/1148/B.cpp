#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int n,m,ta,tb,k;
    scanf("%d %d %d %d %d",&n,&m,&ta,&tb,&k);
    int a[200005];
    int b[200005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i = 0;i<m;i++)
        scanf("%d",&b[i]);
    int ans=0;
    if(k>=n){
        printf("-1\n");
        return 0;
    }
    for(int i = 0;i<=k;i++){
        int go=a[i]+ta;
        int j=lower_bound(b,b+m,go)-b;
        j+=k-i;
        if(j>=m){
            printf("-1\n");
            return 0;
        }
        ans=max(ans,b[j]+tb);
    }
    printf("%d\n",ans);
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i
*/