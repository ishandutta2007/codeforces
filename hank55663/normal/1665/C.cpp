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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
vector<int> v[200005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 2;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    vector<int> tmp;
    for(int i = 1;i<=n;i++){
        if(v[i].size())tmp.pb(v[i].size());
    }
    tmp.pb(1);
    sort(tmp.begin(),tmp.end());
    //reverse(tmp.begin(),tmp.end());
    int ans=tmp.size();
    for(int i = 0;i<tmp.size();i++){
        tmp[i]--;
        tmp[i]-=i;
    }
    int Max=1e9,Min=-1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int tot=0;
        for(auto it:tmp){
            if(it>mid)tot+=it-mid;
        }
        if(tot<=mid)Max=mid;
        else Min=mid;
    }
    ans+=Max;
    printf("%d\n",ans);
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
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/