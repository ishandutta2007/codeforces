#include<bits/stdc++.h>
#define int long long
#define ll long long
inline ll read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	ll k=0,kk=1;if (c=='-')c=getchar(),kk=-1;
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}using namespace std;
int n,m;
signed main(){
	n=read(),m=read();
	if (n==m)puts("Yes");else puts("No");
}