// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=200005;
char s[N];
int f[N][26][2];
int opt[N][26][2];
bool del[N][26][2];
void print(int x,int pos,int id)
{
    if(x<=0||!~pos) return;
    print(x-1,opt[x][pos][id],id^(!del[x][pos][id]));
    if(!del[x][pos][id]) printf("%c",s[x]);
}
int main()
{
	memset(opt,255,sizeof(opt));
    memset(f,63,sizeof(f));
    int n;
    read(n);
    read_str(s+1);
    for(int i=1;i<=n;++i)
    {
        f[i][s[i]-97][1]=i-1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<26;++j)
        {
            if(s[i]!=j+97)
            {
                if(f[i][s[i]-97][0]>f[i-1][j][1])
                {
                    f[i][s[i]-97][0]=f[i-1][j][1];
                    opt[i][s[i]-97][0]=j;
                    del[i][s[i]-97][0]=0;
                }
            }
            if(f[i][s[i]-97][1]>f[i-1][j][0])
            {
                f[i][s[i]-97][1]=f[i-1][j][0];
                opt[i][s[i]-97][1]=j;
                del[i][s[i]-97][0]=0;
            }
        }
        for(int j=0;j<26;++j)
        {
            if(f[i][j][0]>f[i-1][j][0]+1)
            {
                f[i][j][0]=f[i-1][j][0]+1;
                opt[i][j][0]=j;
                del[i][j][0]=1;
            }
            if(f[i][j][1]>f[i-1][j][1]+1)
            {
                f[i][j][1]=f[i-1][j][1]+1;
                opt[i][j][1]=j;
                del[i][j][1]=1;
            }
        }
    }
    int ans=n,pos=26;
    for(int i=0;i<26;++i)
    {
        if(ans>f[n][i][0])
        {
            ans=f[n][i][0];
            pos=i;
        }
    }
    printf("%d\n",ans);
    if(ans==n)
    {
        printf("\n");
        return 0;
    }
    print(n,pos,0);
    printf("\n");
    return 0;
}
//