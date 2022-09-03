#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
void solve(){
    int n,h;
    scanf("%d %d",&n,&h);
    int a[1005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    int tot=h/(a[0]+a[1])*2;
    h%=(a[0]+a[1]);
    if(h==0);
    else if(h<=a[0])tot++;
    else tot+=2;
    printf("%d\n",tot);
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
7
34 38 10
8 32 9
3 7 10
5 13 9
23 40 5
28 34 1
24 26 10
*/