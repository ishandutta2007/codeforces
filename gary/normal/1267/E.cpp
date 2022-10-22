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
int n,m,a[105][105],ans=inf;bool flg[105];pii dif[105];
vector<int> answ;
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,m) rep(j,1,n) scanf("%d",&a[i][j]);
    rep(i,1,n-1){
        rep(j,1,m) dif[j].fi=a[j][n]-a[j][i],dif[j].se=j;
        sort(dif+1,dif+m+1);
        int cur=0,pos=m;
        rep(j,1,m) {
            cur+=dif[j].fi;
            if(cur>0) {pos=j-1;break;}
            flg[dif[j].se]=1;
        }
        if(ans>m-pos){
            ans=m-pos;
            answ.clear();
            rep(j,1,m) if(!flg[j]) answ.pb(j);
        }
        rep(j,1,m) flg[j]=0;
    }
    printf("%d\n",ans);
    rap(i,0,answ.size()) printf("%d ",answ[i]);
    return 0;
}