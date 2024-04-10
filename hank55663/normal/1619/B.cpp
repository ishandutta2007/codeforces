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
    vector<int> v;
void solve(){
    int n;
    scanf("%d",&n);
    printf("%d\n",upper_bound(v.begin(),v.end(),n)-v.begin());
}
int main(){

    for(int i = 1;i*i<=1000000000;i++)v.pb(i*i);
    for(int i = 1;i*i*i<=1000000000;i++)v.pb(i*i*i);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}