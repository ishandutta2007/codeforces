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
        int n;
        scanf("%d",&n);
        int odd=0,even=0;
        for(int i = 0;i<n;i++){
            int x;
            scanf("%d",&x);
            if(x&1)odd++;
            else even++;
        }
        if((odd&&even)||odd%2==1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/