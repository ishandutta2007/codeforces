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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    //for(int i = 1;i<=n;i++)s[i].clear();
    int a[200005],b[200005];
    for(int i = 0;i<n;i++){
        scanf("%d %d",&b[i],&a[i]);
    }
    int Max=n+1,Min=1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int now=0;
        for(int i = 0;i<n;i++){
            if(a[i]>=now&&b[i]>=mid-now-1)now++;
        }
        if(now>=mid)Min=mid;
        else Max=mid;
    }
    printf("%d\n",Min);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/