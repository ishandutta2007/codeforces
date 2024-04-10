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
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[105];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<n-1;i++){
        int sub=min(k,a[i]);
        k-=sub;
        a[i]-=sub;
        a[n-1]+=sub;
    }
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/