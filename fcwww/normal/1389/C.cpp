#include<bits/stdc++.h>
using namespace std;
#define N 200050
char str[N];
int a[N],n,tmp[5];
void solve() {
	scanf("%s",str+1);
	n=strlen(str+1);
	int i,j,ans=n-1;
	for(i=1;i<=n;i++) a[i]=int(str[i]-'0');
	for(i=0;i<=99;i++) {
		tmp[1]=i%10,tmp[0]=i/10;
		int tt=0,now=0;
		for(j=1;j<=n;j++) {
			if(tmp[now]==a[j]) {
				now^=1;
			}else tt++;
		}
		if(tmp[0]^tmp[1]) tt+=now;
		ans=min(ans,tt);
	}
	printf("%d\n",ans);
}
int main() {
	int cas;
	scanf("%d",&cas);
	while(cas--) solve();
}