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
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    if(n==2){
        for(int i  = 0;i<n;i++)printf("%d ",a[i]);
        printf("\n");
        return ;
    }
    int Min=1e9,ans;
    for(int i = 0;i<n-1;i++){
        if(a[i+1]-a[i]<Min){
            Min=a[i+1]-a[i];
            ans=i;
        }
    }
    for(int i = ans+1;i<n;i++)printf("%d ",a[i]);
    for(int i = 0;i<=ans;i++)printf("%d ",a[i]);
    printf("\n");
}
int main(){
    int t=1;//00;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/