#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define ll long long
ll t,n,sum,mx,x[200005];
inline ll read(){
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
} 
inline void work(){
	n=read();
	for(register int i=1;i<=n;i++)x[i]=read();
	mx=x[1],sum=0;
	for(register int i=2;i<=n;i++)if(x[i]*mx<0)sum+=mx,mx=x[i];
	else mx=max(mx,x[i]);
	printf("%lld\n",sum+mx);
}
int main(){
	t=read();
	while(t--)work();
}