#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 4000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
pair<int,int> Ans[MN+5];
int L,n,m,t,b[2][MN+5],A[MN+5],B[MN+5],Lx[MN+5],num,from1[MN+5],from2[MN+5],f1[MN+5],f2[MN+5],ans,Move[MN+5],moveans;
inline void Update(int&f,int&from,int v,int fr){if(v>f)f=v,from=fr;}
inline int F(int k,int x){return k?from2[x]:from1[x];}
int main()
{
    L=read();n=read();m=read();t=read();Lx[num=2]=L;
    for(int i=1;i<=n;++i) A[i]=Lx[++num]=read(),Lx[++num]=A[i]-1;
    for(int i=1;i<=m;++i) B[i]=Lx[++num]=read(),Lx[++num]=B[i]-1;
    sort(Lx+1,Lx+num+1);num=unique(Lx+1,Lx+num+1)-Lx-1;
    for(int i=1;i<=n;++i) b[0][lower_bound(Lx+1,Lx+num+1,A[i])-Lx]=1;
    for(int i=1;i<=m;++i) b[1][lower_bound(Lx+1,Lx+num+1,B[i])-Lx]=1;
    memset(f1,200,sizeof(f1));memset(f2,200,sizeof(f2));f1[1]=0;f2[1]=0;
    for(int i=1;i<num;++i)
    {
        if(f1[i]>=0)
        {
            if(b[0][i+1]) {if(f1[i]>=t) Update(f1[i+1],from1[i+1],f1[i]-t+Lx[i+1]-Lx[i],0);}
            else Update(f1[i+1],from1[i+1],f1[i]+Lx[i+1]-Lx[i],0);
            if(!b[1][i+1])
            {
                if(b[0][i+1]) {if(f1[i]>=t) Update(f2[i+1],from2[i+1],min(f1[i]-t,t-1)+Lx[i+1]-Lx[i],0);}
                else Update(f2[i+1],from2[i+1],min(f1[i],t-1)+Lx[i+1]-Lx[i],0);
            }
        }
        if(f2[i]>=0)
        {
            if(b[1][i+1]) {if(f2[i]>=t) Update(f2[i+1],from2[i+1],f2[i]-t+Lx[i+1]-Lx[i],1);}
            else Update(f2[i+1],from2[i+1],f2[i]+Lx[i+1]-Lx[i],1);
            if(!b[0][i+1])
            {
                if(b[1][i+1]) {if(f2[i]>=t) Update(f1[i+1],from1[i+1],min(f2[i]-t,t-1)+Lx[i+1]-Lx[i],1);}
                else Update(f1[i+1],from1[i+1],min(f2[i],t-1)+Lx[i+1]-Lx[i],1);
            }
        }
     //   cout<<i+1<<" "<<f1[i+1]<<" "<<from1[i+1]<<" "<<f2[i+1]<<" "<<from2[i+1]<<endl;
    }
    if(f1[num]<0&&f2[num]<0) return 0*puts("No"); else puts("Yes");
    int tt=f1[num]<0;
    for(int i=num,j;i>=1;i=j-1,tt^=1)
    {
        int block=b[tt][i+1];
        for(j=i;j>1&&F(tt,j)==tt;--j) block+=b[tt][j];block+=b[tt][j];
      //  cout<<tt<<" "<<i<<" "<<j<<" "<<block<<endl;
        int predp=(tt?f2[j]:f1[j])-(Lx[j]-Lx[j-1]);
      //  cout<<"predp="<<predp<<" "<<(tt?f2[j]:f1[j])<<" "<<t-predp<<" "<<Lx[j-1]+1+max(0,t-predp-1)<<endl;
        for(int k=Lx[j-1]+1+max(0,t-predp-1)+(block-1)*t,tms=block;tms;--tms,k-=t) Ans[++ans]=make_pair(k,tt+1);
        Move[++moveans]=j>1?Lx[j-1]+1:0;
    }
    if(tt) --moveans;
    printf("%d\n",moveans);
    for(int k=moveans;k;--k) printf("%d%c",Move[k],k>1?' ':'\n');
    printf("%d\n",ans);
    for(int k=ans;k;--k) printf("%d %d\n",Ans[k].first,Ans[k].second);
    return 0;
}