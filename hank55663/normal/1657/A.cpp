#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
void solve(){
    int x,y;
    scanf("%d %d",&x,&y);
    int c=sqrt(x*x+y*y);
    if(x==0&&y==0){
        printf("0\n");
    }
    else if(c*c==x*x+y*y){
        printf("1\n");
    }
    else{
        printf("2\n");
    }
}


int main(){
    int t=1;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/