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
using namespace std;
 pii p[200005];
void solve(){
    int n;
    scanf("%d",&n);
    vector<int> ll,rr;
    for(int i = 0;i<n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        p[i]=mp(l,r);
        ll.pb(l);
        rr.pb(r);
    }
    sort(ll.begin(),ll.end());
    sort(rr.begin(),rr.end());
    int ans=n;
    for(int i = 0;i<n;i++){
        int a=ll.end()-upper_bound(ll.begin(),ll.end(),p[i].y);
        int b=lower_bound(rr.begin(),rr.end(),p[i].x)-rr.begin();
        ans=min(ans,a+b);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}