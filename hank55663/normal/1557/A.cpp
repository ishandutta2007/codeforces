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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    int a[100005];
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    LL sum=0;
    for(int i = 0;i<n;i++)sum+=a[i];
    double ans=-1e10;
    LL sum2=0;
    for(int i = 0;i<n-1;i++){
        sum2+=a[i];
        ans=max(ans,sum2*1.0/(i+1)+(sum-sum2)*1.0/(n-i-1));
    }
    printf("%.12f\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

10 10 40000
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 1
*/