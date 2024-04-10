
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fa[200005],a[200005],lst[200005],pre[200005],n,q,mx[200005],ans=0;
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Merge(int x,int y){
	if((x=gf(x))==(y=gf(y)))return ;
	fa[x]=y,mx[y]=max(mx[y],mx[x]);
}
int main(){
	cin>>n>>q,ans=n;
	for(int i=1;i<=n;i++)cin>>a[i],mx[a[i]]++;
	for(int i=1;i<=200000;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		if(lst[a[i]]){
			for(int j=i-1;j>lst[a[i]];j=(pre[j]?pre[j]:j-1))Merge(a[i],a[j]);
		}
		pre[i]=lst[a[i]],lst[a[i]]=i;
	}
	for(int i=1;i<=200000;i++)if(gf(i)==i&&mx[i])ans-=mx[i];
	cout<<ans;
}