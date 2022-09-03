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
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[1005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    int ans=1e9;;
    for(int i = 0;i<n;i++){
       // tot+=a[i];
       if(k%a[i]==0)
        ans = min(ans,(k+a[i]-1)/a[i]);
    }
    printf("%d\n",ans);
}
/*

262143999937856
*/