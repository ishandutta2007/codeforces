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
#define index Index
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(n==1){
        printf("R\n");
        return;
    }
    if(k*2>n+1){
        printf("-1\n");
    }
    else{
        char c[45][45];
        MEM(c);
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                c[i][j]='.';
                if(i==j&&i%2==0&&k){
                    c[i][j]='R';
                    k--;
                }
            }
            printf("%s\n",c[i]);
        }
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
8876666554222188 
*/