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
int main(){
    int n,h;
    scanf("%d %d",&n,&h);
    int cnt=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x>h)cnt+=2;
        else cnt++;
    }
    printf("%d\n",cnt);
}
/*

*/