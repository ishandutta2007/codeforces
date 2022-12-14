#include<bits/stdc++.h>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int num[MN+5],f[8];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline int numor(int x,int y){return num[x]+num[y]-num[gcd(x,y)];}
int main()
{
    for(int i=1;i<=MN;++i) for(int j=i;j<=MN;j+=i) ++num[j];
    for(int T=read();T--;)
    {
        int a=read(),b=read(),c=read();long long ans=0;
        int gab=gcd(a,b),gbc=gcd(b,c),gac=gcd(a,c),gg=gcd(gab,c);
        memset(f,0,sizeof(f));
        f[1]=num[a]-numor(gab,gac);
        f[2]=num[b]-numor(gab,gbc);
        f[4]=num[c]-numor(gac,gbc);
        f[3]=num[gab]-num[gg];
        f[5]=num[gac]-num[gg];
        f[6]=num[gbc]-num[gg];
        f[7]=num[gg];
        for(int i=1;i<=7;++i) for(int j=i+1;j<=7;++j) for(int k=j+1;k<=7;++k) 
            if((i|j|k)==7) ans+=1LL*f[i]*f[j]*f[k];
        for(int i=1;i<=7;++i) 
            if(i!=1&&i!=2&&i!=4) for(int j=1;j<=7;++j) if(j!=i&&(i|j)==7)
                ans+=1LL*f[i]*(f[i]+1)/2*f[j];
        ans+=1LL*f[7]*(f[7]+1)*(f[7]+2)/6;
        printf("%I64d\n",ans);
    }
    return 0;
}