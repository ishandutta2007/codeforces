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
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=1;
    for(int i = 1;i<=n;i++){
        if(a[i]>=ans){
            ans++;
        }
    }
    printf("%d\n",ans-1);
}