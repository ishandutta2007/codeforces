#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    int a[105];
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++){
        if(n*4.5-sum<1e-6)
        break;
        sum+=5-a[i];
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}