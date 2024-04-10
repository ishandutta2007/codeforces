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
typedef vector<int> vt;
string s,t;
int m,n;
const int N=200010;
ull pw[N],a[2][N];
ull get(int i,int j,int o)
{
    return a[o][j]-a[o][i-1]*pw[j-i+1];
}
int main()
{
    //freopen("bai1.inp","r",stdin);
    cin>>m>>n;
    cin>>s>>t;
    bool ok=0;
    int o;
    forinc(i,0,m-1) if(s[i]=='*') {o=i;ok=1;break;}
    if(!ok)
    {
        if(s==t) cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    if(m>n+1){cout<<"NO";
        return 0;}
        pw[0]=1;forinc(i,1,max(m,n)) pw[i]=pw[i-1]*47;
        forinc(i,1,m) a[0][i]=a[0][i-1]*47+s[i-1]-'a';
        forinc(i,1,n) a[1][i]=a[1][i-1]*47+t[i-1]-'a';
        if(o) if(get(1,o,0)!=get(1,o,1)) {cout<<"NO";
        return 0;}int len=m-o-2;
        if(o!=m-1) if(get(o+2,m,0)!=get(n-len,n,1)) {cout<<"NO";
        return 0;}
        cout<<"YES";
}