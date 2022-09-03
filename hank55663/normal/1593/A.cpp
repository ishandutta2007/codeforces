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
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d %d %d\n",max(max(b,c)+1-a,0),max(max(a,c)+1-b,0),max(max(a,b)+1-c,0));
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
*/