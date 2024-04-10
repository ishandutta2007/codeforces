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
const int N=260;
int n,q,f[N][N][N],t[3],a[3][N];
string s;
vector<int> sv[N];
int v(int i,int x)
{
    int c=upper_bound(all(sv[i]),x)-sv[i].begin();
    if(c==sv[i].size()) return n+1;
    return sv[i][c];
}
int F(int i,int j,int k)
{
    if(!i&&!j&&!k) return 0;
    if(f[i][j][k]!=-1) return f[i][j][k];
    int ret=n+1;
    if(i) ret=min(ret,v(a[0][i],F(i-1,j,k)));
    if(j) ret=min(ret,v(a[1][j],F(i,j-1,k)));
    if(k) ret=min(ret,v(a[2][k],F(i,j,k-1)));
    return f[i][j][k]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("b.inp","r",stdin);
    reset(f,-1);
    cin>>n>>q>>s;
    s=' '+s;
    forinc(i,1,n) sv[s[i]-'a'].pb(i);
    while(q--)
    {
        char o;
        cin>>o;
        if(o=='+')
        {
            int i;char c;
            cin>>i>>c;--i;
            a[i][++t[i]]=c-'a';
        }
        else
        {
            int i;cin>>i;--i;
            forinc(j,0,t[(i+1)%3])
            forinc(k,0,t[(i+2)%3])
            {
                if(!i) f[t[i]][j][k]=-1;
                if(i==1) f[k][t[i]][j]=-1;
                if(i==2) f[j][k][t[i]]=-1;
            }
            --t[i];
        }
        if(F(t[0],t[1],t[2])<=n) cout<<"YES\n";
        else cout<<"NO\n";
    }
}