#include<bits/stdc++.h>
using namespace std;
inline int rd(){int x=0,c=0,f=1;for(;c<'0'||c>'9';c=getchar())f=c!='-';
for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';return f?x:-x;}
int main(){
	long long n,k;
	cin>>n>>k;
	n/=k;
	if(n&1)puts("YES");
	else puts("NO");
}