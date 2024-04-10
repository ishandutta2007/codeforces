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
using namespace std;
int cal(int x,int *a,int n){
    int cnt=0;
    int sum=0;
    for(int i = 0;i<n;i++){
        sum+=a[i];
        if(sum==x){
            cnt++;
            sum=0;
        }
        if(sum>x){
            return 0;
        }
    }
    return cnt;
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[3005];
    int sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int ans=0;
    for(int i = 1;i*i<=sum;i++){
        if(sum%i==0){
            ans=max(ans,cal(i,a,n));
            ans=max(ans,cal(sum/i,a,n));
        }
    }
    printf("%d\n",n-ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}