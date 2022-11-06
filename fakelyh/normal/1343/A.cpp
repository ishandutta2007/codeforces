#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define ll long long
ll t,x;
inline ll read(){
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
}
inline void work(){
	x=read();
	for(register int i=2;i<30;i++)if(x%((1<<i)-1)==0)return (void)printf("%d\n",x/((1<<i)-1));
}
int main(){
	t=read();
	while(t--)work();
}