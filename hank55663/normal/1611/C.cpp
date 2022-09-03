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
    deque<int> q;
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(a[0]==n){
        printf("%d ",n);
        for(int i = n-1;i>=1;i--)printf("%d ",a[i]);
        printf("\n");
    }
    else if(a[n-1]==n){
        
        for(int i = n-2;i>=0;i--)printf("%d ",a[i]);
          printf("%d ",n);
        printf("\n");
    }
    else{
        printf("-1\n");
    }
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