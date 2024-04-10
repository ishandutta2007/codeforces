#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=2e5+10,mod=1e9+7;
int n,maxin,Max,sl=1,MAX=INT_MAX,SL;
pii a[N],f[N];
priority_queue<pii,vector<pii>,greater<pii> > heap;
int main()
{
    //freopen("1197E.inp","r",stdin);
    n=in;
    forinc(i,1,n)
    {
        a[i]={in,in};
        swap(a[i].fi,a[i].se);
        maxin=max(maxin,a[i].fi);
    }
    sort(a+1,a+n+1);
    forinc(i,1,n)
    {
        while(!heap.empty()&&heap.top().fi<=a[i].fi)
        {
            int j=heap.top().se;heap.pop();
            int c=f[j].fi-a[j].se;
            if(c<Max) Max=c,sl=0;
            if(c==Max) sl=(sl+f[j].se)%mod;
        }
        f[i]={Max+a[i].fi,sl};
        heap.push({a[i].se,i});
        if(a[i].se>maxin)
        {
            if(f[i].fi<MAX) MAX=f[i].fi,SL=0;
            if(f[i].fi==MAX) SL=(SL+f[i].se)%mod;
        }
    }
    cout<<SL;
}