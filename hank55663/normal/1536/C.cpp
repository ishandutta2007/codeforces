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
    int n;
    scanf("%d",&n);
    char c[500005];
    scanf("%s",c);
    map<pii,int> m;
    int a=0,b=0;
    //m[mp(1,1)]=1;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='D')a++;
        else b++;
        int gcd=__gcd(a,b);
         m[mp(a/gcd,b/gcd)]++;
        printf("%d ",m[mp(a/gcd,b/gcd)]);
       
    }
    printf("\n");
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