#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200005],cnt=1;
int trie[10086001][2],L[10086001],R[10086001];
void insert(LL val,LL id)
{
	LL root=1;
	L[root]=1,R[root]=id;
	for(LL i=30;~i;--i)
	{
		LL p=(val>>i)&1;
		if(!trie[root][p])	trie[root][p]=++cnt;
		root=trie[root][p];
		if(!L[root])	L[root]=id;
		R[root]=id;
	}
}
LL query(LL now,LL val,LL bit)
{
	if(bit==-1)	return 0;
	LL p=(val>>bit)&1;
	if(trie[now][p])	return query(trie[now][p],val,bit-1);
	return query(trie[now][p^1],val,bit-1)+(1<<bit);
}
LL calc(LL now,LL bit)
{
	if(bit==-1)	return 0;
	LL ret=0;
	if(trie[now][0] && trie[now][1])
	{
		LL minn=2e9;
		for(LL i=L[trie[now][0]];i<=R[trie[now][0]];++i)	minn=min(minn,(1<<bit)+query(trie[now][1],a[i],bit-1));
		ret=minn;
	}
	if(trie[now][0])	ret+=calc(trie[now][0],bit-1);
	if(trie[now][1])	ret+=calc(trie[now][1],bit-1);
	return ret;
}
int main(){
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(LL i=1;i<=n;++i)	insert(a[i],i);
	printf("%lld",calc(1,30));
	return 0;
}