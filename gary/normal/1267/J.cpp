#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
int T,n,t[2000005],a,ans;vector<int> v;
void solve(){
    ans=inf;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a);
        t[a]++;
    }
    v.clear();
    int mn=inf;
    rep(i,1,n) if(t[i]!=0) {mn=min(mn,t[i]);v.pb(i);}
    rep(s,1,mn+1){
        bool flg=1;int cur=0;
        rap(ii,0,v.size()) {
            int i=v[ii];
            int rem=t[i]%s,num=t[i]/s;
            //printf("%d %d %d\n",rem,t[i],s);
            if(rem!=0&&s-rem>num+(rem!=0)) {flg=0;break;}
            cur+=num+(rem!=0);
        }
        if(flg) ans=min(ans,cur);
    }
    printf("%d\n",ans);
    rep(i,1,n) t[i]=0;
}
int main()
{
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}