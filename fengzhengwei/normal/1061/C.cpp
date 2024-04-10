#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=1e5+5;
vector<int>v[xx*10];
void pre()
{
	for(int i=1;i<=1e5;i++)
		for(int j=i;j<=1e6;j+=i)v[j].push_back(i);
	for(int i=1;i<=1e6;i++)reverse(v[i].begin(),v[i].end());
}
const int mod=1e9+7;
int a[xx],f[xx*10];
int red(int x){return x>=mod?x-mod:x;}
int main(){
	pre();
	n=read();
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		for(int j=0;j<v[a[i]].size();j++)f[v[a[i]][j]]=red(f[v[a[i]][j]]+f[v[a[i]][j]-1]);
	}
	int ans=0;
	for(int i=1;i<=1e6;i++)ans=red(ans+f[i]);
	cout<<ans<<"\n";
	return 0;
}