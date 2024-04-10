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
int T;
int h,m;
int to[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
bool check(int x,int y)
{
	int a=0,b=0;
	if(to[y%10]==-1)return 0;
	a+=to[y%10];y/=10;a*=10;
	if(to[y%10]==-1)return 0;
	a+=to[y%10];y/=10;
	if(to[x%10]==-1)return 0;
	b+=to[x%10];x/=10;b*=10;
	if(to[x%10]==-1)return 0;
	b+=to[x%10];x/=10;
	if(a<h&&b<m)return 1;
	return 0;
}
void print(int x)
{
	int a,b;
	a=x%10;
	x/=10;
	b=x%10;
	cout<<b<<a;
}
int main(){
	T=read();
	while(T--)
	{
		h=read();
		m=read();
		int a,b;
		a=read();
		b=read();
		while(1)
		{
			if(check(a,b))
			{
				print(a),cout<<":",print(b),puts("");
				break;
			}
			b++;
			if(b==m)a++,b=0;
			if(a==h)a=0;
		}
	}
	return 0;
}