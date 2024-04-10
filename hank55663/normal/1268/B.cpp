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
    int n;
    scanf("%d",&n);
    LL odd=0,even=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        odd+=x/2;
        even+=x/2;
        odd+=x%2;
        swap(odd,even);
    }
    printf("%lld\n",min(odd,even));
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/