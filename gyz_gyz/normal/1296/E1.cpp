#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
char s[N],t[N];int tot,a[N];
int main(){int n;tot=-1;
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n)rep(j,0,tot+1)if(s[i]>=t[j]){
		if(j>tot)++tot;
		a[i]=j;t[j]=s[i];break;
	}
	if(tot>1)return printf("NO\n"),0;
	printf("YES\n");
	rep(i,1,n)printf("%d",a[i]);
}