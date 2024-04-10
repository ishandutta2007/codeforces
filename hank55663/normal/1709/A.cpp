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
#define double long double
using namespace std;
void solve(){
    int x;
    scanf("%d",&x);
    int a[4];
    scanf("%d %d %d",&a[1],&a[2],&a[3]);
    int now=x;
    int cnt=0;
    while(now){
        cnt++;
        now=a[now];
    }
    if(cnt==3)printf("YES\n");
    else printf("NO\n");
}
int main(){
    int t=1;000;
    scanf("%d",&t);
    while(t--){
       
        solve();
    }
    
}
/*
*/