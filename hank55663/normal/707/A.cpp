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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
const int mod=1e9+7;
int main(){ 
    int n,m;
    scanf("%d %d",&n,&m);
    int ok=0;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            scanf(" %c",&c);
            if(c=='C'||c=='M'||c=='Y')ok=1;
        }
    }
    if(ok)printf("#Color\n");
    else printf("#Black&White\n");
}
/*
1 2 2 3 3 3 4
2 2 1
3 2 3
4 2 4 4 7
 
1 1
*/