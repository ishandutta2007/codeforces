#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
inline int read()
{
    int  x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int k,cnt=0,n;
string name[55],s;
char st[555];
int res[55];

string getnewname()
{
	cnt++;s="A";
	for(int i=cnt;i>0;i-=26)s=s+(char)((i-1)%26+'a');
	return s;
}

int pd(){scanf("%s",st+1);return st[1]=='Y'?1:0;}

int main()
{
	n=read();k=read();
	for(int i=1;i+k-1<=n;i++) res[i]=pd();
	for(int i=1;i<=n;i++)name[i]=getnewname();
	for(int i=n-k+1;i;i--)if(res[i]) name[i]=getnewname();
	else name[i]=name[i+k-1];
	for(int i=1;i<=n;i++)cout<<name[i]<<" ";
	return 0;
}