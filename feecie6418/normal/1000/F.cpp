#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005],bel[500005],ans[500005],st[5005],ed[5005],sum[5005];
struct Query{
	int l,r,id;
	bool operator <(const Query y) const {
		return bel[l]!=bel[y.l]?bel[l]<bel[y.l]:(bel[l]&1?r<y.r:r>y.r);
	}
}q[500005];
int Q(){
	for(int i=bel[500000];i;i--){
		if(!sum[i])continue;
		for(int j=ed[i];bel[j]=i;j--)if(cnt[j]==1)return j;
	}
	return 0;
}
void Add(int x){
	if(cnt[x]==1)sum[bel[x]]--;
	if(cnt[x]==0)sum[bel[x]]++;
	cnt[x]++;
}
void Del(int x){
	if(cnt[x]==1)sum[bel[x]]--;
	if(cnt[x]==2)sum[bel[x]]++;
	cnt[x]--;
}
int main(){
	scanf("%d",&n);
	for(int i=1,c=1000;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1,c=1000;i<=500000;i++)bel[i]=i/c+1,ed[bel[i]]=i;
	for(int i=1;i<=m;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1);
	int nowl=1,nowr=0;
	for(int i=1;i<=m;i++){
		while(nowl<q[i].l)Del(a[nowl++]);
		while(nowl>q[i].l)Add(a[--nowl]);
		while(nowr<q[i].r)Add(a[++nowr]);
		while(nowr>q[i].r)Del(a[nowr--]);
		ans[q[i].id]=Q();
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}