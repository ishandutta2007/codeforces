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
    int l[3];
    for(int i = 0;i<3;i++){
        scanf("%d",&l[i]);
    }
    sort(l,l+3);
    if(l[2]==l[0]+l[1]){
        printf("Yes\n");
    }
    else if(l[0]==l[1]&&l[2]%2==0){
        printf("Yes\n");
    }
    else if(l[1]==l[2]&&l[0]%2==0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
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