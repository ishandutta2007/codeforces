#include<bits/stdc++.h>
using namespace std;
int Abs(int x){return x>0?x:-x;}
int n,a[1005],pos[1005];
void Solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%1d",&a[i]);
	for(int i=1;i<=n;++i)	if(a[i-1]>a[i])	goto fail;
	puts("0");
	return ;
	fail:;
	int cnt=0;
	for(int i=1;i<=n;++i)	if(a[i])	pos[++cnt]=i;
	vector<int> Z,O;
	for(int i=n-cnt+1;i<=n;++i)	if(!a[i])	Z.push_back(i);
	for(int i=1;i<=n-cnt;++i)	if(a[i])	O.push_back(i);
	puts("1");
	printf("%d",int(Z.size()+O.size()));
	for(auto st:O)	printf(" %d",st);
	for(auto st:Z)	printf(" %d",st);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}