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
int dfs(int l,int r,int n,int last){
    if(l==r)return l;
    int mid=(l+r)/2;
    int add=((n-mid-1)%n+n)%n;
    printf("+ %d\n",add);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    if(x==last)return dfs(l+add,mid+add,n,last);//-add;
    else return dfs(mid+add+1,r+add,n,x);//-add;
}   
void solve(){
    int last=0;
    int n;
    scanf("%d",&n);
    printf("! %d\n",dfs(1,n-1,n,0));
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}