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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char a[55],b[55];
    scanf("%s %s",a,b);
    int l=n-1,r=m-1;
    while(r>=1){
        if(b[r]!=a[l]){
            printf("NO\n");
            return;
        }
        r--;
        l--;
    }
    for(int i = 0;i<=l;i++){
        if(a[i]==b[0]){
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/