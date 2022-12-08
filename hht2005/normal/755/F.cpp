#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bitset<N>f;
int p[N],in[N],v[N],t[N];
int main() {
	int n,k,m=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	for(int i=1;i<=n;i++) {
		if(in[i])continue;
		m++;
		while(!in[i]) {
			v[m]++;
			in[i]=1;
			i=p[i];
		}
	}
	int c1=0,c2=0;
	for(int i=1;i<=m;i++) {
		t[v[i]]++;
		c1+=v[i]/2;
		c2+=v[i]%2;
	}
	f[0]=1;
	for(int i=1;i<=n;i++) {
		int p=1;
		while(p<=t[i])f|=f<<(p*i),t[i]-=p,p*=2;
		if(t[i])f|=f<<(t[i]*i);
	}
	printf("%d %d\n",!(f[k])+k,min(k,c1)*2+min(max(k-c1,0),c2));
	return 0;
}