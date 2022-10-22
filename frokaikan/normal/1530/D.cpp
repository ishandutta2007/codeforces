#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 200000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header

int a[maxn+5],b[maxn+5];
int cnt[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,n) cnt[i]=0;
        rep(i,1,n) cnt[a[i]]++;
        int ans=0;
        rep(i,1,n) ans+=cnt[i]>0;
        printf("%d\n",ans);
        set<int> s,arb;
        rep(i,1,n) s.insert(i);
        rep(i,1,n) b[i]=0;
        rep(i,1,n) if(s.count(a[i])) b[i]=a[i],s.erase(a[i]); else arb.insert(i);
        vi same;
        rep(i,1,n) if(b[i]==0) b[i]=*s.begin(),s.erase(s.begin());
        rep(i,1,n) if(b[i]==i) same.pb(i);
        if(same.size()==1)
        {
            int x=same[0];
            if(arb.size()==1)
            {
                assert(ans==n-1);
                int y=-1;
                rep(i,1,n) if(i!=x && a[i]==a[x]) {y=i; break;}
                assert(y!=-1);
                swap(b[x],b[y]);; 
            }
            else
            {
                assert(arb.count(x)>0);
                arb.erase(x);
                int y=*arb.begin();
                swap(b[x],b[y]);
            }
        }
        else if(same.size()>1)
        {
            int N=same.size();
            rep(i,0,N-2) swap(b[same[i]],b[same[i+1]]);
        }       
        int check=0;
        rep(i,1,n) assert(b[i]!=i),check+=b[i]==a[i];
        rep(i,1,n) printf("%d%c",b[i]," \n"[i==n]);
        sort(b+1,b+n+1);
        rep(i,1,n) assert(b[i]==i);
    }
	return 0;
}