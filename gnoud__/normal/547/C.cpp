#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
void read(int & x) {x=0;char c=getchar();while(c<'0'||c>'9') c=getchar();while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}}
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forv(a,b) for(auto&a:b)
#define read2(a,b) read(a),read(b)
using namespace std;
const int N=5e5+10;
int n,p[N],m,a[N],top,k,x[N],dd[N],fre[N],f[N];
ll sl;
void snt()
{
    forinc(i,2,N-10) if(!p[i])
    for(int j=i;j<=N-10;j+=i) p[j]=i;
}
void add(int i,int l,int hash)
{
    if(!top) return;
    if(i==top+1)
    {
        if(hash==1) return;
        sl+=f[hash]*((l%2)?1:-1);
        f[hash]++;
    }
    else
    {
        add(i+1,l,hash);
        add(i+1,l^1,hash*a[i]);
    }
}
void rev(int i,int l,int hash)
{
    if(!top) return;
    if(i==top+1)
    {
        if(hash==1) return;
        f[hash]--;
        sl+=f[hash]*((l%2)?-1:1);
    }
    else
    {
        rev(i+1,l,hash);
        rev(i+1,l^1,hash*a[i]);
    }
}
int main()
{
    //freopen("547C.inp","r",stdin);
    snt();
    read2(n,m);
    forinc(i,1,n) read(x[i]);
    while(m--)
    {
        int i;read(i);
        int s=x[i];
        top=0;
        while(s!=1)
        {
            if(!fre[p[s]])
            a[++top]=p[s],fre[p[s]]=1;
            s/=p[s];
        }
        if(!dd[i]) k++,add(1,0,1);
        else k--,rev(1,0,1);
        dd[i]^=1;
        cout<<1ll*k*(k-1)/2-sl<<"\n";
        s=x[i];
        while(s!=1) fre[p[s]]=0,s/=p[s];
    }
}