#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
char s[N];
int n;
int f[N];
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	f[1]=1;
	int i,an=n,fx=1,y=0;
	for(i=2;i<=n;++i){
		f[i]=(s[i]^s[i-1]?f[i-1]:0)+1;
		if(f[i]==1)
			an=min(an,i-1);
		fx=max(fx,f[i]);
	}
	for(i=n-1;i;--i)
		if(s[i]==s[i+1])
			break;
	if(i==1 || an==n)
	{
		printf("%d\n",n);
		return 0;
	}
	//cerr<<n<<" "<<i<<" "<<an<<endl;
	if(s[1]^s[n])fx=max(fx,an+n-i);
	printf("%d\n",fx);
}