#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int to[100005],Len[100005],i,j,m,n,p,k;
int a[100005],fox[100005],k1,st[100005];
struct Node{int ed,before;}s[1000005];
char c,S[100001];
void add(int x,int y)  {s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; }
int main()
{ for (c=getchar();c!='\n';c=getchar()) a[++a[0]]=c-'0';
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  { scanf("%s",&S);
    st[i]=S[0]-'0';
      int len=strlen(S);
    for (j=len-1;j>2;j--) add(i,S[j]-'0');
  }
  	for (i=0;i<=9;i++) to[i]=i,Len[i]=10;
  for (;n;n--)
{    long long A=1,B=0;
   int x=st[n];
    for (i=fox[n];i;i=s[i].before)
    {   int y=s[i].ed;
        (A*=Len[y])%=Mo;
        B=(B*Len[y]+to[y])%Mo;
    }
    Len[x]=A;
    to[x]=B;
}
long long ans=0;
for(i=1;i<=a[0];i++)
  ans=(ans*Len[a[i]]+to[a[i]])%Mo;
printf("%I64d\n",ans);
}