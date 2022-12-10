#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
int a[N],p[N],f1[N],f2[N],pro[N],c1[N],c2[N],fac[N],tot,n;
vector<int>d[N];
#define End return puts("0"),0
int num(int x) {
	if(x==1)return 1;
	return n/x;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)pro[i]=1;
	for(int i=2;i<=n;i++) {
		if(!d[i].empty())continue;
		p[++tot]=i;
		for(int j=i;j<=n;j+=i)
			d[j].push_back(i),pro[j]*=i;
		c1[n/i]++;
	}
	d[1].push_back(1);
	c1[1]++;
	for(int i=1;i<=n;i++)
		c2[pro[i]]++;
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		if(!a[i])continue;
		if(d[a[i]].size()!=d[i].size())End;
		for(int j=0;j+1u<d[i].size();j++)
			if(d[a[i]][j]!=d[i][j])End;
		int x=d[a[i]].back(),y=d[i].back();
		if(num(x)!=num(y))End;
		if(f1[x]&&f1[x]!=y)End;
		if(f2[y]&&f2[y]!=x)End;
		if(!f1[x])c1[num(x)]--;
		c2[pro[a[i]]]--;
		f1[x]=y;
		f2[y]=x;
	}
	fac[0]=1;
	int ans=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n;i++)
		ans=1ll*ans*fac[c1[i]]%mod*fac[c2[i]]%mod;
	printf("%d\n",ans);
	return 0;
}