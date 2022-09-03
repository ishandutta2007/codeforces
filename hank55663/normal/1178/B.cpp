#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    char c[1000005];
    scanf("%s",c);
    LL cnt[3];
    MEM(cnt);
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='v'&&c[i+1]=='v'){
            cnt[0]++;
            cnt[2]+=cnt[1];
        }
        else if(c[i]=='o'){
            cnt[1]+=cnt[0];
        }
    }
    printf("%lld\n",cnt[2]);
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/