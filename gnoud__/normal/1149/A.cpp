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
const int N=1e6+10;
int n,p[N],snt[N],top,s[3];
void Snt()
{
    forinc(i,2,N-10) if(!p[i])
    {
        snt[++top]=i;
        for(int j=i*2;j<=N-10;j+=i) p[j]=i;
    }
}
bool cheq(int x)
{
    int s1=0,s2=0,X=0;
    while(X<=x-2&&s2<s[2]) X+=2,s2++;
    while(X<=x-1&&s1<s[1]) X++,s1++;
    if(X==x)
    {
        s[1]-=s1;
        s[2]-=s2;
        while(s1--) cout<<1<<" ";
        while(s2--) cout<<2<<" ";
        return 1;
    }
    return 0;
}
inline void read(int &x)
{
    x=0;
    char c=getchar();
    bool neg=false;
    while(c!='-'&&('0'>c||c>'9')) c=getchar();
    if(c=='-') neg=true,c=getchar();
    while('0'<=c&&c<='9') x=10*x+c-'0',c=getchar();
    if(neg) x=-x;
}
int main()
{
    //freopen("a.inp","r",stdin);
    read(n);
    Snt();
    forinc(i,1,n)
    {
        int x;
        read(x);
        s[x]++;
    }
    forinc(i,1,top)
    {
        int S=(snt[i]-snt[i-1]);
        if(cheq(S)) continue;
        else
        {
            while(s[1]--) cout<<1<<" ";
            while(s[2]--) cout<<2<<" ";
            return 0;
        }
    }
}