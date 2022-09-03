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
const int mod=998244353;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[105];
    scanf("%s",c);
    string str(c),str2(c);
    reverse(str2.begin(),str2.end());
    if(k==0){
        printf("1\n");
    }
    else if(str==str2)printf("1\n");
    else printf("2\n");
} 
/*
LLRLLR
012345
LRLL
*/
int main(){
   /* for(int i = 2;i<=1000000;i++){
        if(v[i].empty())
        for(int j = i;j<=1000000;j+=i )v[j].pb(i);
    }*/
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567

RRRRR
6 4 4 4
5 3 4 4
4 3 3 4
4 2 4 4
3 2 3 4
4 4 2 4


*/