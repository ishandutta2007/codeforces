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
    LL s,n,k;
    scanf("%lld %lld %lld",&s,&n,&k);
    if(k>s){
        printf("NO\n");
    }
    else if(s==k){
        printf("YES\n");
    }
    else{
        s-=n;
        LL tot=s/k+1;
        if((__int128)tot*(k-1)+tot-1>=n){
            printf("NO\n");
        }
        else{
            s+=n;
            LL need=(s-k+1)*2+(n-2);
            if(need<=s){
                printf("NO\n");
            }
            else
            printf("YES\n");
        }
    }
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
60.0 0.0 50.0 170.0 
3
40.0 0.0 0.0 0.0
5.0 20.0 5.0 170.0
95.0 0.0 95.0 80.0


0.0 1.0 4.0 1.0 
1
0.0 0.0 4.0 0.0
*/