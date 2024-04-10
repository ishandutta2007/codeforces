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
#define pdd pair<double,double>
#define cpdd const pdd
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[1005][1005];
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
    }
    int ans=0;
    for(int i = 0;i<m;i++){
        int x;
        scanf("%d",&x);
        int cnt[5];
        MEM(cnt);
        for(int j = 0;j<n;j++){
            cnt[c[j][i]-'A']++;
        }
        int Max=0;
        for(int j=0;j<5;j++){
            Max=max(Max,cnt[j]);
        }
        ans+=Max*x;
    }
    printf("%d\n",ans);
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000

 */