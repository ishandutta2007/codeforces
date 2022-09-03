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
#define ld long double
int cnt[400005];
int main(){
    int q,x;
    scanf("%d %d",&q,&x);
    int now=0;
    while(q--){
        int y;
        scanf("%d",&y);
        cnt[y%x]++;
        while(cnt[now%x]){
            cnt[now%x]--;
            now++;
        }
        printf("%d\n",now);
    }
}