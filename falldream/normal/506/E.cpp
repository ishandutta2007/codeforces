#include<bits/stdc++.h>
#define MN 200
#define mod 10007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char st[MN+5];
int S,n,f[MN+5][MN+5][MN+5],Val[MN+5],Len,a[405];
long long tmp[405][405],b[405];
inline void R(int&x,int y){(x+=y)>=mod?x-=mod:0;}
struct Matrix
{
    int s[405][405];
    Matrix(){memset(s,0,sizeof(s));}
    void Mul()
    {
        for(int i=0;i<Len;++i) for(int k=0;k<=i;++k) if(s[i][k])
            for(int j=0;j<=k;++j)
                tmp[i][j]+=s[i][k]*s[k][j];
        for(int i=0;i<Len;++i) for(int j=0;j<Len;++j) s[i][j]=tmp[i][j]%mod,tmp[i][j]=0;
    }
    void print()
    {
        for(int i=0;i<Len;++i,puts(""))
            for(int j=0;j<Len;++j) printf("%d ",s[i][j]);
    }
}A;
int Solve(int self,int len)
{
 //   cout<<"Solve"<<self<<" "<<len<<endl;
    int num24=0,num25=0;
    for(int i=0;i<=n;++i) if(Val[i])
    {
        num24=max(num24,i);
        num25=max(num25,n-i+1>>1);
      //  cout<<i<<" "<<Val[i]<<endl;
    }
  //  cout<<"num="<<num24<<" "<<num25<<endl;
    Len=num24+num25+1;
    memset(A.s,0,sizeof(A.s));
    for(int i=0;i<num24;++i) A.s[i][i]=24;
    for(int i=1;i<num24;++i) A.s[i][i-1]=1;
    for(int i=0;i<num25;++i) A.s[num24+i][num24+i]=25;
    for(int j=1;j<num25;++j) A.s[num24+j][num24+j-1]=1;
    if(num25) A.s[num24+num25][num24+num25-1]=1;
    A.s[num24+num25][num24+num25]=self;
    memset(a,0,sizeof(a));
    for(int i=0;i<=n;++i) if(Val[i])
    {
        int n1=i,n2=n-i+1>>1;
        if(!i) R(a[num24],Val[i]);
        else R(A.s[num24+num25-n2][n1-1],Val[i]);   
    }
    //A.print();
    if(num24) R(a[0],1);
    for(;len;len>>=1,A.Mul()) if(len&1)
    {
        for(int i=0;i<Len;++i) for(int j=0;j<=i;++j) b[i]+=a[j]*A.s[i][j];
        for(int i=0;i<Len;++i) a[i]=b[i]%mod,b[i]=0;
    }
    return a[Len-1];
}
int main()
{
    scanf("%s",st+1);n=strlen(st+1);S=read();
    f[1][n][0]=1;
    for(int i=1;i<=n;++i) for(int j=n;j>=i;--j) for(int k=0;k<=n;++k) if(f[i][j][k])
        if(st[i]==st[j])
        {
          //  cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
            if(j-i>1) R(f[i+1][j-1][k],f[i][j][k]);
            else R(Val[k],f[i][j][k]);
        }
        else
        {
           // cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
            R(f[i+1][j][k+1],f[i][j][k]);
            R(f[i][j-1][k+1],f[i][j][k]);
        }
    int ans=Solve(26,n+S>>1);
    if((n+S)&1)
    {
        memset(Val,0,sizeof(Val));
        for(int i=1;i<=n;++i) for(int k=0;k<=n;++k) R(Val[k],f[i][i][k]);//cout<<i<<" "<<k<<" = "<<f[i][i][k]<<endl;
        --n;ans=(ans*26+Solve(25,n+1+S>>1))%mod;
    }
    printf("%d\n",ans);
    return 0;
}