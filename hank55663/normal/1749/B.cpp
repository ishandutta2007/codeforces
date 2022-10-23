#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;

void solve(int T){
    int n;
    scanf("%d",&n);
    int a[200005],b[200005];
    LL sum=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    for(int i = 0;i<n;i++)scanf("%d",&b[i]);
    sort(b,b+n);
    for(int i = 0;i<n-1;i++)sum+=b[i];
    printf("%lld\n",sum);
}

int main(){
  //  srand(time(NULL));
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*575855273
1
2 4
3 
5
*/