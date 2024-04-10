#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int n,m;
int s[200005];
int odd=1,even=2;
int oddnum=0,evennum=0;
map<int,bool> mp;
int ans=0;
bool b[200005];

bool yes=true;

int getodd()
{
    while(mp[odd]&&odd<=m) odd+=2;
    if(odd>m) {yes=false;return 0;}
    odd+=2;return odd-2;
}

int geteven()
{
    while(mp[even]&&even<=m) even+=2;
    if(even>m){yes=false;return 0;}
    even+=2;return even-2;
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
        s[i]=read();
    for(int i=1;i<=n;i++)
    {
        if(s[i]&1){if(oddnum<n/2&&!mp[s[i]]){ b[i]=1;mp[s[i]]=1;oddnum++;}}
        else{if(evennum<n/2&&!mp[s[i]]) {b[i]=1;mp[s[i]]=1;evennum++;}}
    }
//    cout<<oddnum<<" "<<evennum<<endl;
    for(int i=1;i<=n;i++)
    {
        if(b[i]) continue;ans++;
        if(oddnum==n/2) s[i]=geteven(),evennum++;
        else s[i]=getodd(),oddnum++;
    }
    if(yes==false){printf("-1");return 0;}
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d ",s[i]);
    return 0;
}