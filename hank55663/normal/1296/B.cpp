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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int s;
        scanf("%d",&s);
        LL use=0;
        while(s>=10){
            use+=s/10*10;
            LL tmp=s/10;
            s-=tmp*10;
            s+=tmp;
        }
        use+=s;
        printf("%lld\n",use);
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/