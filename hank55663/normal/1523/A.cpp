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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=998244353;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[1005];
    scanf("%s",c+1);
    c[0]=0;
    for(int i=0;i<m;i++){
        char c2[1005];
        for(int j = 1;j<=n;j++){
            int cnt=0;
            if(c[j-1]=='1')cnt++;
            if(c[j+1]=='1')cnt++;
            if(cnt==1)c2[j]='1';
            else c2[j]=c[j];
        }
        int ok=0;
        for(int j=1;j<=n;j++){
            if(c2[j]!=c[j])ok=1;
            c[j]=c2[j];
        }
        if(!ok)break;
    }
    printf("%s\n",c+1);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/