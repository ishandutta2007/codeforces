#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
int n;
long long x,y;
char s[N];
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	cin>>n>>x>>y;
	scanf("%s",s+1);
	int l=0,i;
	for(i=1;i<=n;++i)
		if(s[i]=='0'&&s[i-1]!='0')++l;
	if(!l)puts("0");
	else if(x>y)cout<<y*l;
	else cout<<x*(l-1)+y;
}