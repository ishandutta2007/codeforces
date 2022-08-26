#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+3;
typedef vector<int> vi;
typedef long long ll;
int x,y,z,n;
int sg[maxn][3],dp[7][7][7],period;
ll a[maxn];
bool check(int p,int q){
    bool ret=1;
    for (int i=0;i<3;i++) ret&=sg[p][i]==sg[q][i];
    return ret;
}
int mex(vi a){
    bool f[10];
    for (int i=0;i<10;i++) f[i]=0;
    for (auto x:a) f[x]=1;
    int ret=0;
    while (f[ret]) ++ret;
    return ret;
}
int work(ll x,int y){
    if (x<0) x=0;
    if (x<=2000) return sg[x][y];
    x-=(x-500)/period*period;
    return sg[x][y];
}
int main(){
    //freopen("input.txt","r",stdin);
    int _;scanf("%d",&_);
    while (_--){
        scanf("%d%d%d%d",&n,&x,&y,&z);
        for (int i=1;i<=2000;i++){
            sg[i][0]=mex((vi){sg[max(0,i-x)][0],sg[max(0,i-y)][1],sg[max(0,i-z)][2]});
            sg[i][1]=mex((vi){sg[max(0,i-x)][0],sg[max(0,i-z)][2]});
            sg[i][2]=mex((vi){sg[max(0,i-x)][0],sg[max(0,i-y)][1]});
        }
        period=0;
        if (dp[x][y][z]) period=dp[x][y][z];
        else {
            for (int j=1;j<=500;j++){
                bool flag=1;
                for (int k=500;k+j<=2000;k++) flag&=check(k,k+j);
                if (flag) {
                    period=j;break;
                }
            }
            assert(period);
            dp[x][y][z]=period;
        }
        int sum=0;
        for (int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum^=work(a[i],0);
        }
        int cnt=0;
        for (int i=1;i<=n;i++){
            int res=sum^work(a[i],0);
            if (res==work(a[i]-x,0)) ++cnt;
            if (res==work(a[i]-y,1)) ++cnt;
            if (res==work(a[i]-z,2)) ++cnt;
        }
        printf("%d\n",cnt);
    }
    return 0;
}