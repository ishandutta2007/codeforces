#include<bits/stdc++.h>
using namespace std;
inline int rd(){int x=0,c=0,f=1;for(;c<'0'||c>'9';c=getchar())f=c!='-';
for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';return f?x:-x;}
int main(){
	int s,v1,v2,t1,t2;
	scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	int a=v1*s+2*t1,b=v2*s+2*t2;
	if(a==b)puts("Friendship");
	else puts(a<b?"First":"Second");
}