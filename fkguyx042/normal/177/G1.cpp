#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=1000000007;
int i,j,m,k,flag,CA;
long long n;
int A[2],B[2][2],sky[3],dec[3][3];
char c[100005],p[100005];
int Zero[100005],One[100005],ans,S[100005],E[100005],G[100005];
void Ch()
{ 
       int i,j,k,C[2]={0};
       for (k=0;k<2;++k)
           for (j=0;j<2;++j) 
            (C[j]+=1ll*A[k]*B[k][j]%Mo)%=Mo;
       memcpy(A,C,sizeof(A));
}
void ch()
{
       int i,j,k,C[2][2]={0};
       for (k=0;k<2;++k)
         for (i=0;i<2;++i)
           for (j=0;j<2;++j)
             (C[i][j]+=1ll*B[i][k]*B[k][j]%Mo)%=Mo;
       memcpy(B,C,sizeof(B));
}
int Get1(long long x)
{
       A[0]=1; A[1]=0; B[0][0]=0; B[1][0]=1; B[1][1]=1; B[0][1]=1; --x;
       for (;x;x>>=1)
       {
             if (x&1) Ch();
             ch();
       }
   return A[1];
}
int Get2(long long x)
{
       A[0]=0; A[1]=1; B[0][0]=0; B[1][0]=1; B[1][1]=1; B[0][1]=1; --x;
       for (;x;x>>=1)
       {
             if (x&1) Ch();
             ch();
       }
       return A[1];
}
void P() {   int C[3]={0},i,j,k;
             for (k=0;k<3;++k)
               for (j=0;j<3;++j) (C[j]+=1ll*sky[k]*dec[k][j]%Mo)%=Mo;
             memcpy(sky,C,sizeof(sky));
          }
void P1() { 
     int C[3][3]={0},i,j,k;
       for (k=0;k<3;++k)
         for (i=0;i<3;++i)
           for (j=0;j<3;++j)
             (C[i][j]+=1ll*dec[i][k]*dec[k][j]%Mo)%=Mo;
       memcpy(dec,C,sizeof(dec));
}
int Get3(long long x)
{
      sky[0]=sky[1]=0; sky[2]=1;
      --x;
      int flag=0;
      if (x&1) flag=1; x/=2;
      dec[0][0]=1; dec[0][1]=1; dec[0][2]=0;
      dec[1][0]=1; dec[1][1]=2; dec[1][2]=0;
      dec[2][0]=0; dec[2][1]=1; dec[2][2]=1;
      for (;x;x>>=1)
      {  
         if (x&1) P(); P1();
      }
      if (flag) 
   {   
     memset(dec,0,sizeof(dec));
     dec[1][0]=1;
     dec[1][1]=1;
     dec[0][1]=1;
     dec[2][2]=1;
     P();
   }
   return sky[1];
}
void dfs(int x,char *y,int Len)
{ 
       if (Len==2&&y[1]=='0'&&y[2]=='1') 
       {
           (ans+=G[x])%=Mo; return;
       }
      if (Len==1) (ans+=y[1]=='0'?Zero[x]:One[x])%=Mo;
      else
      {
           if (n-x==0) return; 
           int LenA=0;
           int i;
           for (i=1;i<Len;)
              if (y[i]=='0')
              { 
                  if (i!=1) return;
                  p[++LenA]='1';
                  ++i;
              }
              else
              {
                     if (y[i+1]=='0') p[++LenA]='1',i+=2;
                     else p[++LenA]='0',++i;
              }
           if (i==Len) 
           {
               if (y[Len]=='0') return;
                 ++LenA;
                 char P1[100005];
                  for (i=1;i<=LenA;++i) P1[i]=p[i];
                 p[LenA]='0'; dfs(x+1,p,LenA);
                 P1[LenA]='1'; dfs(x+1,P1,LenA);
           }
           else dfs(x+1,p,LenA);
         }	
}           
void Cheat()
{
	for (i=0;i<=n;++i) Zero[i]=One[i]=G[i]=S[i]=E[i]=0;
    Zero[0]=1;
    One[1]=1;
    for (i=2;i<=n;++i) Zero[i]=(Zero[i-1]+Zero[i-2])%Mo,One[i]=(One[i-1]+One[i-2])%Mo;
    G[0]=G[1]=0;
    S[0]=0; S[1]=1; E[0]=0;E[1]=1;
    for (i=2;i<=n;++i)
    {
          G[i]=(G[i-1]+G[i-2])%Mo;
          if (E[i-1]==0&&S[i-2]==1) (G[i]+=1)%=Mo;
          S[i]=1; E[i]=E[i-2];
    }  
    for (i=0;i<=n/2;++i) swap(Zero[i],Zero[n-i]),swap(One[i],One[n-i]),swap(G[i],G[n-i]);
       int Len=strlen(c);
       for (i=Len;i;--i) c[i]=c[i-1];
       dfs(0,c,Len);
      printf("%d\n",ans);
}
void F()
{
      int Len=strlen(c);
      for (i=Len;i;--i) c[i]=c[i-1];
      dfs(0,c,Len);
      printf("%d\n",ans);
}
int main()
{
    scanf("%I64d",&n); scanf("%d",&m); n--;
    if(n>5000)
    {
	  for (i=0;i<=1000;++i) Zero[i]=Get1(n-i);
      for (i=0;i<=1000;++i) One[i]=Get2(n-i);
      for (i=0;i<=1000;++i) G[i]=Get3(n-i); 
    }
    for (;m--;)
  {
  	ans=0;
    scanf("%s",&c);
    int len=strlen(c);
    for (i=0;i<len;++i) c[i]=c[i]-'a'+'0';
    if (n<=5000) Cheat();
    else F();
  }
}