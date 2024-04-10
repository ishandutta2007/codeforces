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
    int n;
    scanf("%d",&n);
    int a[55];
    int ok=1;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=i)ok=0;
    }
    if(ok){
        printf("0\n");
    }
    else if(a[1]==1||a[n]==n){
        printf("1\n");
    }
    else if(a[1]==n&&a[n]==1){
        printf("3\n");
    }
    else{
        printf("2\n");
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*
a b
b a
b a a
a a b
a a b b
a b b a
a b b a a
a b a a b
a b a b a

*/