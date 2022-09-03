#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-7
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[1005];
        scanf("%s",c+1);
        int pre[1005],suf[1005];
        MEM(pre);
        MEM(suf);
        int len=strlen(c+1);
        pre[0]=0;
        for(int i = 1;c[i]!=0;i++){
            pre[i]=pre[i-1]+c[i]-'0';
        }
        for(int i  =len;i>=1;i--){
            suf[i]=suf[i+1]+c[i]-'0';
        }
        int ans=1000;
        for(int i = 0;i<=len;i++){
            ans=min(ans,min(pre[i],i-pre[i])+min(suf[i+1],len-i-suf[i+1]));
        }
        printf("%d\n",ans);
    }
}
/*
2 11 14
9 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
3**5+3**5-2**5
000111222
001112220
*/