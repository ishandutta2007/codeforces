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
const int N=510;
int n,res;
int dag[N],x[N];
vector<pii> kq;
void read( int &x)
{
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') c = getchar(), nega = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
bool cmp(int u,int v) {return dag[u]<dag[v];}
int main()
{
    //freopen("d.inp","r",stdin);
    read(n);
    forinc(i,1,n) read(dag[i]);
    forinc(i,1,n) x[i]=i;
    sort(x+1,x+n+1,cmp);
    int j=1;
    forinc(i,1,n) if(dag[x[i]]<2) j=i+1;
    forinc(i,j,n-1)
    {
        kq.pb({x[i],x[i+1]});
        dag[x[i]]--,dag[x[i+1]]--;
    }
    if(j>1) kq.pb({x[1],x[n]}),dag[x[n]]--,res++;
    int o=j,ok=0;
    forinc(i,2,j-1) if(dag[x[i]]==1)
    {
        while(o<=n&&!dag[x[o]]) o++;
        if(o>n) {cout<<"NO";return 0;}
        kq.pb({x[i],x[o]});dag[x[o]]--;
        ok=1;
    }
    int KQ=n-j+res+ok;
    cout<<"YES "<<KQ<<"\n";
    cout<<kq.size()<<"\n";
    forv(v,kq) cout<<v.fi<<" "<<v.se<<"\n";
}