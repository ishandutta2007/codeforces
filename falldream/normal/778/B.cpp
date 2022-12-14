#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ID 20170226
#define ll long long
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
string st,st2,name;
map<string,int> mp;
char s[10000];
int mark[5005][3];
int x[5005][1005],x2[5005][1005];
int n,m,ans[5005];
char op[5005];
int f[5005];

int check(int j,int def)
{
    int x1,y1,tot=0;
    for(int i=1;i<=n;i++)
    {
        if(mark[i][1]==ID) x1=x[i][j];
        else if(mark[i][1]==-1) x1=def;
        else x1=f[mark[i][1]];
        if(mark[i][2]==ID)y1=x2[i][j];
        else if(mark[i][2]==-1) y1=def;
        else y1=f[mark[i][2]];
       // cout<<i<<" "<<j<<" "<<x1<<" "<<y1<<endl;
        if(op[i]=='O') x1=x1|y1;
        if(op[i]=='A') x1=x1&y1;
        if(op[i]=='X') x1=x1^y1;
        f[i]=x1;tot+=x1;
    }
    return tot;
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        int nown=0;
        cin>>name;mp[name]=i;
        scanf("%s",s);cin>>st;
        if(getchar()!='\n')
        {
            scanf("%s",s);
            cin>>st2;
            if(st2=="?") mark[i][2]=-1;
            else if(st2[0]>='0'&&st2[0]<='9')
            { mark[i][2]=ID;for(int j=0;j<m;j++) x2[i][j]=st2[j]-'0';}
            else mark[i][2]=mp[st2];
            op[i]=s[0];
        }
        else mark[i][2]=ID,op[i]='O';
        if(st=="?") mark[i][1]=-1;
        else if(st[0]>='0'&&st[0]<='9')
        { mark[i][1]=ID;for(int j=0;j<m;j++) x[i][j]=st[j]-'0';}
        else mark[i][1]=mp[st];

    }
    for(int i=0;i<m;i++)
    {
        int x=check(i,0);int y=check(i,1);
        if(x>y) printf("1");
        else if(x==y) printf("0");
        else printf("0"),ans[i]=1;
    }
    puts("");
    for(int i=0;i<m;i++)printf("%d",ans[i]);
    return 0;
}