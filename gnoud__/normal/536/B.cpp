#include <bits/stdc++.h>
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define read2(a,b) read(a),read(b)
using namespace std;
typedef vector<int> vt;
const int mod=1000000007,M=47,N=1000010;
int n,m,dd[N],a[N],b[N],l,dem,nex[N],A[N],pw[N],Hash;
string s;
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
    //freopen("536B.inp","r",stdin);
    read2(n,m);pw[0]=1;forinc(i,1,n) pw[i]=pw[i-1]*M;
    cin>>s;forinc(i,0,s.size()-1) a[i+1]=s[i]-'a'+1;l=s.size();
    nex[1]=0;forinc(i,2,l)
    {
        int j=nex[i-1];
        while(j&&a[j+1]!=a[i]) j=nex[j];
        if(a[j+1]==a[i]) j++;nex[i]=j;
    }
    forinc(i,1,m) {int x;read(x);dd[x]=1;b[x]+=1;b[x+l]-=1;}
    forinc(i,1,n) {b[i]+=b[i-1];if(!b[i]) dem++;}
    int j=1;forinc(i,1,n)
    {
        if(!dd[i]) {j=max(j,i+1);continue;}
        if(j>=i+l) continue;
        forinc(t,j,i+l-1) {A[t]=a[t-i+1];j=i+l;}
    }
    j=0;forinc(i,1,n)
    {
        while(j&&A[i]!=a[j+1]) j=nex[j];
        if(a[j+1]==A[i]) j++;
        if(i>=l&&dd[i-l+1]&&j!=l) {cout<<0;return 0;}
        if(j==l) j=nex[j];
    }
    long long ds=1; forinc(i,1,dem) ds=(ds*26)%mod; cout<<ds;
}