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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
void solve(){
    int n,x;
    scanf("%d %d",&n,&x);
    int a[100005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    int ans=0;
    int cnt=0;
    for(int i = 0;i<n;i++){
        cnt++;
        if(a[i]*cnt>=x){
            ans++;
            cnt=0;
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}