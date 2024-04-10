#include<bits/stdc++.h>
using namespace std;
char s[105];
const int M=998244353;
int dp[105][2][20][16][16],n,ans,a,b,d;
int calc(int x,int o,int r,int mask1,int mask2){
    if (x==n) {
        if (r!=0) return 0;
        if (mask1&mask2) return 1;
        return 0;
    }
    int &ret=dp[x][o][r+a][mask1][mask2];
    if (ret!=-1) return ret;
    ret=0;
    if (!o){
        for (int i=0;i<=9;i++)
        for (int j=0;j<=s[x]-'0';j++){
            int p=r*10-i*b+j*a;
            if (p<=-a||p>=b) continue;
            int w1=(i>0&&i%a==0&&i<=d*a)?1<<(i/a-1):0;
            int w2=(j>0&&j%b==0)?1<<(j/b-1):0;
            (ret+=calc(x+1,j<(s[x]-'0'),p,mask1|w1,mask2|w2))%=M;
        }
    } else {
        for (int i=0;i<=9;i++)
        for (int j=0;j<=9;j++){
            int p=r*10-i*b+j*a;
            if (p<=-a||p>=b) continue;
            int w1=(i>0&&i%a==0&&i<=d*a)?1<<(i/a-1):0;
            int w2=(j>0&&j%b==0)?1<<(j/b-1):0;
            (ret+=calc(x+1,1,p,mask1|w1,mask2|w2))%=M;
        }
    }
    return ret;
}

int main(){
    scanf("%s",s); n=strlen(s);
    for (int i=0;i<n;i++) ans=(1ll*ans*10+s[i]-'0')%M;
    for (a=1;a<=9;a++)
    for (b=a+1;b<=9;b++) if (__gcd(a,b)==1){
        memset(dp,-1,sizeof(dp)); d=9/b;
        ans=(1ll*calc(0,0,0,0,0)*2+ans)%M;
    }
    cout << ans << endl;
}