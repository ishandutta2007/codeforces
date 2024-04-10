#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define stop system("pause")
#define fi first
#define se second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define pb push_back
#define mp make_pair
#define pp pop_back()
#define mp3(a,b,c) mp(a,mp(b,c))
#define mp4(a,b,c,d) mp(mp(a,b),mp(c,d))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(min(a,d),min(b,c))
#define pii pair<int,int>
#define piii pair<int,pii >
#define pi4 pair<pair<int,int>,pair<int,int>>
#define all(a) a.begin(),a.end()
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define two(n) (1<<n)
#define bit(x,i) ((x>>(i-1))&1)
#define batbit(x,i) (x|(1ll<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
#define read4(a,b,c,d) read(a),read(b),read(c),read(d)
#define gcd(a,b) abs(__gcd(a,b))
#define lim 2139062143
using namespace std;
const int N=200010;
int n,a[N],ok,c[N],sum,x[N],ans[N];
pii b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("a.inp","r",stdin);
    cin>>n;
    forinc(i,1,n) cin>>b[i].fi,b[i].se=i;
    sort(b+1,b+n+1);
    int top=0;
    forinc(i,1,n)
    {
        if(!a[i])
        {
            top++;
            int cl=n-b[i].fi;
            c[top]=b[i].fi;
            if(i+cl-1>n) ok=1;
            forinc(j,i,i+cl-1) a[j]=top;
        }
        else if(c[a[i]]!=b[i].fi) ok=1;
    }
    forinc(i,1,n) x[a[i]]++;
    forinc(i,1,n) if(n-x[a[i]]!=b[i].fi) ok=1;
    if(ok) cout<<"Impossible";
    else
    {
        cout<<"Possible\n";
        forinc(i,1,n) ans[b[i].se]=a[i];
        forinc(i,1,n) cout<<ans[i]<<" ";
    }
}