#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int read() {
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
int js(int x)
{
	if(x<0)return -1;
	int res=0;
	while(x)res+=x%10,x/=10;
	return res;
}
signed main() {
	n=read();
	vector<int>v;
	for(int i=0;i<=90;i++)
	{
		if(js(n-i)==i)v.push_back(n-i);
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<"\n";
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
	puts("");
	return 0;
}