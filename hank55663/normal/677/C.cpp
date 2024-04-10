#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int num(char c){
    if(c>='0'&&c<='9')return c-'0';
    if(c>='A'&&c<='Z')return c-'A'+10;
    if(c>='a'&&c<='z')return c-'a'+36;
    if(c=='-')return 62;
    if(c=='_')return 63;
    return 63;
}
LL Pow[7]={1,3,9,27,81,243,729};
int main(){
    LL ans=1;
    char c;
    int mod=1e9+7;
    while(scanf("%c",&c)!=EOF){
        int x=num(c);
        int y=__builtin_popcount(x);
        ans*=Pow[6-y];
        ans%=mod;
    }
    printf("%lld\n",ans);
}
/*

*/