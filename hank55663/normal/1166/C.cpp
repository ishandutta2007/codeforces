#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        v.pb(abs(x));
    }
    sort(v.begin(),v.end());
    LL ans=0;
    for(int i = 0;i<n;i++){
        ans+=i-(lower_bound(v.begin(),v.end(),(v[i]+1)/2)-v.begin());
    }
    printf("%lld\n",ans);
}