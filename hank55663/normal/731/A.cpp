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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int main() {
    char c[1005];
    scanf("%s",c);
    int ans=0;
    char last='a';
    for(int i = 0;c[i]!=0;i++){
        ans+=min(abs(c[i]-last),26-abs(c[i]-last));
       // printf("%d\n",ans);
        last=c[i];
    }
    printf("%d\n",ans);
    return 0;
}