#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
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
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
vector<int> e;
map<int,int> dd,pw;
int main()
{
    forinc(i,0,30)
    {
        dd[(1<<i)-1]=1;
        pw[1<<i]=i;
    }
    int x;cin>>x;
    int ok=0;
    while(!dd[x])
    {
        if(pw[x])
        {
            ok=1;
            e.pb(pw[x]);break;
        }
        int top=31;
        while(!bit(x,top)) top--;
        x^=((1<<top)-1);
        x++;
        e.pb(top);
    }
    cout<<e.size()*2-ok<<"\n";
    forv(x,e) cout<<x<<" ";
}