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
LL a[200005],b[200005],m[200005];
bool cmp(const int &x,const int &y){
    return a[x]<a[y];
}
void solve(){
    int n;
    scanf("%d",&n);

    LL ea[200005],eb[200005];
    map<int,vector<int> > ma;
    for(int i = 0;i<n;i++){
        scanf("%lld %lld %lld",&a[i],&b[i],&m[i]);
        ma[a[i]+b[i]-m[i]].pb(i);
    }
    int ans=0;
    for(auto it:ma){
        sort(it.y.begin(),it.y.end(),cmp);
        int lasta=-1e9,lastb=-1e9;;
        for(auto it2:it.y){
           // printf("%d\n",it2);
            if(a[it2]-m[it2]>lasta){
                ans++;
                lasta=a[it2];
                lastb=b[it2]-m[it2];
                if(lastb<0){
                    lasta+=lastb;
                    lastb=0;
                }
            }
            eb[it2]=b[it2]-lastb;
            ea[it2]=a[it2]-lasta;
        }
    }
    printf("%d\n",ans);
    for(int i = 0;i<n;i++)printf("%lld %lld\n",ea[i],eb[i]);
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