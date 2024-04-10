#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define ll long long
ll t,n;
long long int sum;
inline ll read(){
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
} 
inline void work(){
	n=read()>>1;
	if(n&1)return (void)puts("NO");
	puts("YES"),sum=0;
	for(register int i=1;i<=n;i++)sum+=(i<<1),printf("%d ",i<<1);
	for(register int i=1;i<n;i++)sum-=((i<<1)-1),printf("%d ",((i<<1)-1));
	printf("%lld\n",sum);
}
int main(){
	t=read();
	while(t--)work();
}