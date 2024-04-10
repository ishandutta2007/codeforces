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
    int n,k;
    scanf("%d %d",&n,&k);
    int x[400005];
    for(int i = 0;i<k;i++)scanf("%d",&x[i]);
    sort(x,x+k);
    reverse(x,x+k);
    int ans=0;
    int sum=0;
    for(int i = 0;i<k;i++){
        if(sum<x[i]){
            ans++;
            sum+=n-x[i];
        }
        else{
            break;
        }
    }
    printf("%d\n",ans);
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