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
int n,l,k,m;string s,t[1005];bool flg[1005];
int main()
{
    fastio;
    cin>>n>>l>>k;
    m=n*l;
    cin>>s;
    sort(s.begin(),s.end());
    rep(i,1,k) {
        t[i]+=s[i-1];
    }
    int p=k;
    rep(i,1,k) flg[i]=1;
    rep(j,1,n) if(j!=k&&flg[j]&&t[j][0]!=t[k][0]) flg[j]=0;
    rep(i,2,l){
        rep(j,1,n) if(flg[j]){
            t[j]+=s[p];
            p++;
        }
        rep(j,1,n) if(j!=k&&flg[j]&&t[j][i-1]!=t[k][i-1]) flg[j]=0;
    }
    rep(i,1,n)
    while(t[i].size()<l) {t[i]+=s[p];p++;}
    rep(i,1,n) cout<<t[i]<<'\n';
    return 0;
}