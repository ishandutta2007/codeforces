#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
#define mod 9875321
#include<map>
#include<cstring>
char s[55]; 
map<int,bool> mp;
int ans=0;
int main()
{
    scanf("%s",s);
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
       int x=0;
       for(int j=1,k=i;j<=l;j++,k=(k+1)%l)
	{
	    x=(x*27+s[k])%mod;
	}
       if(!mp[x]) mp[x]=1,ans++;
    }    
    cout<<ans;
    return 0;
}