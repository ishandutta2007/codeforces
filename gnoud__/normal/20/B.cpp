#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define int long long
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
#define db double
using namespace std;
const db ESP=1e-9;
main()
{
    //freopen("PT.inp","r",stdin);
    cout<<setprecision(10)<<fixed;
    int a,b,c;
    cin>>a>>b>>c;
    if(a==0)
    {
        if(b==0)
        {
            if(c==0) cout<<-1;
            else cout<<0;
        }
        else cout<<1<<"\n"<<db(-c)/b;
        return 0;
    }
    int del=b*b-4ll*a*c;
    if(abs(del)<1e-9)
    {
        cout<<1<<"\n";
        cout<<db(-b)/(2ll*a);
    }
    else if(del<0) cout<<0;
    else
    {
        cout<<2<<"\n";
        db x1=(-b-sqrt(del))/(2ll*a);
        db x2=(-b+sqrt(del))/(2ll*a);
        if(x1>x2) swap(x1,x2);
        cout<<x1<<"\n"<<x2;
    }
}