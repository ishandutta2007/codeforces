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
    int n;
    scanf("%d",&n);
    char c[105];
    scanf("%s",c);
    int cnt[26];
    fill(cnt,cnt+26,0);
    for(int i = 0;c[i]!=0;i++){
        cnt[c[i]-'A']++;
    }
    LL ans=min(cnt['U'-'A'],cnt['D'-'A'])*2+min(cnt['L'-'A'],cnt['R'-'A'])*2;
    printf("%lld\n",ans);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/