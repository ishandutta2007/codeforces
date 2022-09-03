#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    char c[1005];
    scanf("%s",c);
    LL cnt[2]={0,0};
    LL ans=0;
    for(int i=0;c[i]!=0;i++){
        if(c[i]=='Q'){
            ans+=cnt[1];
            cnt[0]++;
        }
        if(c[i]=='A'){
            cnt[1]+=cnt[0];
        }
    }
    printf("%lld\n",ans);
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i
*/