#include<bits/stdc++.h>
#pragma optimize(Ofast)
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<LL,LL>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    char a[1005];
    char b[1005];
    
    for(int i = 0;i<n;i++){
        scanf(" %c",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    vector<int> v;
    for(int i = 0;i<n;i++){
        if(b[i]!=a[i])v.pb(i);
    }
    if(v.size()){
        printf("%d\n%d",1,v.size());
        for(auto it:v)printf(" %d",it+1);
        printf("\n");
    }
    else{
        printf("0\n");
    }
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/