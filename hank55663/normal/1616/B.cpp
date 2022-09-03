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
const int mod=1e9+7;
void solve(){
    int n;
    scanf("%d",&n);
    char c[100005];
    scanf("%s",c);
    if(c[1]>=c[0]||n==1){
        printf("%c%c\n",c[0],c[0]);
    }
    else{
        for(int i=1;c[i]!=0;i++){
            if(c[i]>c[i-1]){
                for(int j = 0;j<i;j++){
                    printf("%c",c[j]);
                }
                for(int j = i-1;j>=0;j--){
                    printf("%c",c[j]);
                }
                printf("\n");
                return;
            }
        }
        printf("%s",c);
        reverse(c,c+n);
        printf("%s\n",c);
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