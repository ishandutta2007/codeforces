#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,m,N,i,j,x,y,tip,Ras,mod,sum[1200009],A[1200009],B[1200009],fib[300009],sf[300009],a[300009],s[300009];
/////////////////////////////////////////////////////matrice
struct str
{
    int v[3][3];
}mat[300009];
str inm(str a,str b)
{
    int i,j,kp;
    long long s;
    str rez;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            s=0;
            for(kp=0;kp<N;kp++)
                s=s+1LL*a.v[i][kp]*b.v[kp][j];
            rez.v[i][j]=s%mod;
        }
    return rez;
}
/////////////////////////////////////////////////////matrice
int calcS(int A,int B,int l)
{
    if(l==1) return A;
    if(l==2) return (A+B)%mod;
    if(l==3) return ((long long)1LL*2*A+1LL*2*B)%mod;
    int a1,a2,a3;
    a1=(1LL*A*mat[l-2].v[0][2])%mod;
    a2=(1LL*B*mat[l-2].v[1][2])%mod;
    a3=(1LL*(A+B)*mat[l-2].v[2][2])%mod;
    return ((long long)a1+a2+a3)%mod;
}
void calcAB(int A,int B,int l,int &a,int &b)
{
    if(l==2) a=A,b=B;
    else
    if(l==3) a=B,b=(A+B)%mod;
    else
    {
        int a1,a2,a3;
        a1=(1LL*A*mat[l-2].v[0][0])%mod;
        a2=(1LL*B*mat[l-2].v[1][0])%mod;
        a3=(1LL*(A+B)*mat[l-2].v[2][0])%mod;
        a=((long long)a1+a2+a3)%mod;

        a1=(1LL*A*mat[l-2].v[0][1])%mod;
        a2=(1LL*B*mat[l-2].v[1][1])%mod;
        a3=(1LL*(A+B)*mat[l-2].v[2][1])%mod;
        b=((long long)a1+a2+a3)%mod;
    }
}
void Chk(int &x)
{
    if(x>=mod) x-=mod;
}
int sumfib(int l,int r)
{
    int nr=sf[r]-sf[l-1];
    if(nr<0) nr+=mod;
    return nr;
}
void split(int nod,int st,int dr,int mij)
{
    if(A[nod]==0&&B[nod]==0) return;
    int L=(nod<<1),R=(nod<<1)+1;

    A[L]+=A[nod];Chk(A[L]);
    B[L]+=B[nod];Chk(B[L]);
    sum[L]+=calcS(A[nod],B[nod],mij-st+1);Chk(sum[L]);

    int na,nb;
    calcAB(A[nod],B[nod],mij-st+3,na,nb);
    A[R]+=na;Chk(A[R]);
    B[R]+=nb;Chk(B[R]);
    sum[R]+=calcS(na,nb,dr-mij);Chk(sum[R]);

    A[nod]=B[nod]=0;
}
void U(int nod,int st,int dr,int x,int y)
{
    if(x<=st&&dr<=y)
    {
        if(st==dr)
        {
            A[nod]+=fib[st-x+1];
            if(A[nod]>=mod) A[nod]-=mod;
            sum[nod]=A[nod];
        }
        else
        {
            A[nod]+=fib[st-x+1];
            if(A[nod]>=mod) A[nod]-=mod;
            B[nod]+=fib[st-x+2];
            if(B[nod]>=mod) B[nod]-=mod;
            sum[nod]+=sumfib(st-x+1,dr-x+1);
            if(sum[nod]>=mod) sum[nod]-=mod;
        }
        return;
    }
    int mij=(st+dr)>>1;
    split(nod,st,dr,mij);
    if(x<=mij) U(nod<<1,st,mij,x,y);
    if(y>mij) U((nod<<1)+1,mij+1,dr,x,y);
    sum[nod]=sum[nod<<1]+sum[(nod<<1)+1];
    if(sum[nod]>=mod) sum[nod]-=mod;
}
void Q(int nod,int st,int dr,int x,int y)
{
    if(x<=st&&dr<=y)
    {
        Ras+=sum[nod];
        if(Ras>=mod) Ras-=mod;
        return;
    }
    int mij=(st+dr)>>1;
    split(nod,st,dr,mij);
    if(x<=mij) Q(nod<<1,st,mij,x,y);
    if(y>mij) Q((nod<<1)+1,mij+1,dr,x,y);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
mod=1000000009;
N=3;
for(i=0;i<N;i++)
    for(j=0;j<N;j++)
        mat[1].v[i][j]=1;
mat[1].v[0][0]=mat[1].v[2][0]=mat[1].v[2][1]=0;
for(i=2;i<=n;i++)
    mat[i]=inm(mat[i-1],mat[1]);
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    s[i]=s[i-1]+a[i];
    if(s[i]>=mod) s[i]-=mod;
}
fib[1]=fib[2]=1;
for(i=3;i<=n;i++)
{
    fib[i]=fib[i-1]+fib[i-2];
    if(fib[i]>=mod) fib[i]-=mod;
}
for(i=1;i<=n;i++)
{
    sf[i]=sf[i-1]+fib[i];
    if(sf[i]>=mod) sf[i]-=mod;
}
while(m)
{
    m--;
    scanf("%d%d%d",&tip,&x,&y);
    if(tip==1)
        U(1,1,n,x,y);
    else
    {
        Ras=s[y]-s[x-1];
        if(Ras<0) Ras+=mod;
        Q(1,1,n,x,y);
        printf("%d\n",Ras);
    }
}
return 0;
}