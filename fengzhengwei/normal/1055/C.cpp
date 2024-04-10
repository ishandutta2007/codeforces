#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main(){
	int l1=read(),r1=read(),t1=read(),l2=read(),r2=read(),t2=read();
	if(l1>l2)swap(l1,l2),swap(r1,r2),swap(t1,t2);
	int d=gcd(t1,t2);
	cout<<max(0,max(min(r2,r1+(l2-l1)/d*d)-l2+1,min(r2,r1+((l2-l1)/d+1)*d)-(l1+((l2-l1)/d+1)*d)+1));
	return 0;
}