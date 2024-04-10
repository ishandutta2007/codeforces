#include<bits/stdc++.h>
const int N=200005;
char s[N];int a[N],b[N],n,q,l,r;
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=2;i<=n;++i)a[i]=a[i-1]+(s[i]=='0'&&s[i-1]=='0'),b[i]=b[i-1]+(s[i]=='1'&&s[i-1]=='1');
	while(q--)scanf("%d%d",&l,&r),printf("%d\n",std::max(a[r]-a[l],b[r]-b[l])+1);
	return 0;
}