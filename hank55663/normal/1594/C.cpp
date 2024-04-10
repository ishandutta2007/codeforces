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
int cnt[300005];
void solve(){
    int n;
    char res;
    scanf("%d %c",&n,&res);
    char c[300005];
    scanf("%s",c+1);
    fill(cnt,cnt+n+1,0);
    int ok=1;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]!=res)cnt[i]++,ok=0;
    }
    if(ok)printf("0\n");
    else{
        for(int i = 2;i<=n;i++){
            int ok=1;
            for(int j = i;j<=n;j+=i){
                if(cnt[j])ok=0;
            }
            if(ok){
                printf("1\n%d\n",i);
                return;
            }
        }
        printf("2\n");
        for(int i = 2;i<=n;i++){
            if(n%i){
                printf("%d %d\n",i,n);
                return;
            }
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