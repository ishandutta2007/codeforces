#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
string s="What are you doing at the end of the world? Are you busy? Will you save us?";
string a1="What are you doing while sending \"";
string a2="\"? Are you busy? Will you send \"";
string a3="\"?";
int n,cnt;long long k,len[MN+5];
char Calc(int x,long long d)
{
    //cout<<"Calc"<<x<<" "<<d<<endl;
    if(x==0) return s[d-1];
    if(d<=a1.length()) return a1[d-1];d-=a1.length();
    if(d<=len[x-1]) return Calc(x-1,d);d-=len[x-1];
    if(d<=a2.length()) return a2[d-1];d-=a2.length();
    if(d<=len[x-1]) return Calc(x-1,d);d-=len[x-1];
    return a3[d-1];
}
int main()
{
  //  cout<<a1;
    len[0]=s.length();
    for(int i=1;i<=MN;++i) len[i]=min((long long)2e18,(long long)(2*len[i-1]+a1.length()+a2.length()+a3.length()));
    for(int Q=read();Q;--Q)
    {
        cin>>n>>k;
        if(k>len[n]) printf(".");
        else printf("%c",Calc(n,k));
    }
    return 0;
}