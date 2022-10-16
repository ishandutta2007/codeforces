#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;                                                                              
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}

int main(){
	ll a;
	cin>>a;
	__int128 o=18*45;
	int p=17;
	while(p--)o*=10,o%=a;
//	cout<<o<<"!!!\n";
	cout<<(ll)(a-o)<<" "<<(ll)(a-o-1+(ll)(1e18))<<"\n";
	return 0;
}