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
const int mod=1e9+7;
int val[1<<19];
char c[300005];
void solve(){
    int k;
    scanf("%d %s",&k,c+1);
    reverse(c+1,c+(1<<k));
    for(int i = (1<<k);i<(1<<k+1);i++){
        val[i]=1;
    }
    for(int i = (1<<k)-1;i>=0;i--){
        if(c[i]=='1')val[i]=val[i<<1];
        else if(c[i]=='0')val[i]=val[(i<<1)+1];
        else val[i]=val[i<<1]+val[(i<<1)+1];
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int p;
        char cc;
        scanf(" %d %c",&p,&cc);
        p=(1<<k)-p;
        c[p]=cc;
        int i = p;
        while(i){
            if(c[i]=='1')val[i]=val[i<<1];
            else if(c[i]=='0')val[i]=val[(i<<1)+1];
            else val[i]=val[i<<1]+val[(i<<1)+1];
            i>>=1;
        }
      //  printf("%s\n",c+1);
        printf("%d\n",val[1]);
    }
} 
/*
C[n-(k-1)*(i-1)][n-i-(k-1)*(i+1)]
//[n-k*i+i-k+1][i]
*/
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/