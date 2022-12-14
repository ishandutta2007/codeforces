#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bool found=0;
int n,yes[50],ap[50],ans=0,res=0;
char st[MN+5],op[5];
int main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        scanf("%s%s",op+1,st+1);
        
        if(found)
        {
            if(op[1]=='?'||op[1]=='!') ++ans;
            continue;
        }
        
        if(op[1]=='?')
        {
            yes[st[1]-'a']=1;
            int tot=0,last=0;
            for(int j=0;j<26;++j) if(yes[j]) ++tot; else last=j;
            if(tot==25) found=1,res=last;
            continue;
        }
        memset(ap,0,sizeof(ap));
        for(int j=1;st[j];++j)ap[st[j]-'a']=1;
        for(int j=0;j<26;++j)
            if(op[1]=='.'&&ap[j]) yes[j]=1;
            else if(op[1]=='!'&&!ap[j]) yes[j]=1;
        int tot=0,last=0;
        for(int j=0;j<26;++j) if(yes[j]) ++tot; else last=j;
        if(tot==25) found=1,res=last;
        //cout<<found<<" "<<res<<endl;
    }
    printf("%d\n",ans);
    return 0;
}