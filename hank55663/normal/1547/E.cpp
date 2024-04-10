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
#define last Last
#define MXN 200005
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int tmp[300005];
    fill(tmp,tmp+n,2e9);
    int a[300005];
    for(int i = 0;i<k;i++)scanf("%d",&a[i]);
    for(int i = 0;i<k;i++){
        int x;
        scanf("%d",&x);
        tmp[a[i]-1]=min(tmp[a[i]-1],x);
    }
    for(int i = 1;i<n;i++){
        tmp[i]=min(tmp[i],tmp[i-1]+1);
    }
    for(int i = n-2;i>=0;i--){
        tmp[i]=min(tmp[i+1]+1,tmp[i]);
    }
    for(int i = 0;i<n;i++)printf("%d ",tmp[i]);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}