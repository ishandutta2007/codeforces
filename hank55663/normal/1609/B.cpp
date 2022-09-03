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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    char c[1000005];
    scanf("%s",c);
    int ans=0;
    for(int i = 0;i+2<n;i++){
        if(c[i]=='a'&&c[i+1]=='b'&&c[i+2]=='c')ans++;
    }
    while(q--){
        int pos;
        char cc;
        scanf("%d %c",&pos,&cc);
        pos--;
        for(int st=-2;st<=0&&pos+st+2<n;st++){
            if(c[pos+st]=='a'&&c[pos+st+1]=='b'&&c[pos+st+2]=='c')ans--;
        }
        c[pos]=cc;
         for(int st=-2;st<=0&&pos+st+2<n;st++){
            if(c[pos+st]=='a'&&c[pos+st+1]=='b'&&c[pos+st+2]=='c')ans++;
        }
        printf("%d\n",ans);
    }
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/