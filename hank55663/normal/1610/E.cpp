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
const int mod=1e9+7;
const int inv=(mod+1)/2;
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    map<LL,int> m;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    LL ans=0;
    for(auto it:m){
        LL sum=it.y;
        LL add=1;
        while(m.lower_bound(it.x+add)!=m.end()){
            auto it2=m.lower_bound(it.x+add);
            sum++;
            add=(it2->x-it.x)*2;
        }
        ans=max(ans,sum);
    }
    printf("%lld\n",n-ans);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
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