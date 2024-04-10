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
    int n;
    scanf("%d",&n);
    int a[10005][5];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(n%2==1){
        printf("NO\n");
        return;
    }
    for(int i = 0;i<5;i++){
        for(int j = i+1;j<5;j++){
            int cnt1=0,cnt2=0,cnt3=0;
            int ok=1;
            for(int k = 0;k<n;k++){
                if(a[k][i]&&a[k][j])cnt3++;
                else if(a[k][i])cnt1++;
                else if(a[k][j])cnt2++;
                else ok=0;
            }
            if(ok&&cnt1<=n/2&&cnt2<=n/2){
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
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