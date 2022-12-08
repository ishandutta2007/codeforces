#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
long long l[N];
char s[N];
signed main() {
	int n,T=0,sum=0,FL=0,w=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",l+i);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++,sum=min(sum,w)) {
		if(s[i]=='G')T+=l[i]*5,sum+=2*l[i],w+=l[i];
		if(s[i]=='W')T+=l[i]*3,FL=1,w+=l[i];
		if(s[i]=='L') {
			w-=l[i];
			T+=l[i];
			if(w>=0)continue;
			if(FL)T+=-w*3;
			else T+=-w*5;
			w=0;
		}
	}
	if(!w)printf("%lld\n",T);
	else printf("%lld\n",T-2*sum-(w-sum));
	return 0;
}