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
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    char c[200005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    scanf("%s",c);
    vector<int> v[2];
    for(int i = 0;i<n;i++){
        if(c[i]=='R')v[0].pb(a[i]);
        else v[1].pb(a[i]);
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    for(int i = 0;i<v[1].size();i++){
        if(v[1][i]<=i){
            printf("NO\n");
            return;
        }
    }
    reverse(v[0].begin(),v[0].end());
    for(int i = 0;i<v[0].size();i++){
        if(v[0][i]>n-i){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
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