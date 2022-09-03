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
void solve(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    char c[105];
    scanf("%s",c);
    if(b>=0)printf("%d\n",a*n+b*n);
    else{
        int tot=1;
        for(int i = 1;c[i]!=0;i++){
            if(c[i]!=c[i-1])tot++;
        }
        printf("%d\n",a*n+b*((tot+2)/2));
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}