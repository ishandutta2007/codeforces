#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k;
#define maxn 100010
int a[maxn];
struct Q{
	int l,r,id;
	ll ans;
}q[maxn*10];
int be[maxn],unit;
int cnt[maxn*40];
bool cmp1(Q z1,Q z2){return be[z1.l]==be[z2.l]?z1.r<z2.r:be[z1.l]<be[z2.l];}
bool cmp2(Q z1,Q z2){return z1.id<z2.id;}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	unit=sqrt(n+1);
	for(int i=1;i<=n+1;++i)be[i]=i/unit+1;
	for(int i=2;i<=n+1;++i){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].r++;q[i].id=i;
	}
	sort(q+1,q+m+1,cmp1);
	ll Ans=0;
	int l=1,r=0;
	for(int i=1;i<=m;++i){
		while(l<q[i].l){cnt[a[l]]--;Ans-=cnt[a[l]^k];l++;}
		while(q[i].l<l){l--;Ans+=cnt[a[l]^k];cnt[a[l]]++;}
		while(q[i].r<r){cnt[a[r]]--;Ans-=cnt[a[r]^k];r--;}
		while(r<q[i].r){r++;Ans+=cnt[a[r]^k];cnt[a[r]]++;}
		q[i].ans=Ans;
	}
	sort(q+1,q+m+1,cmp2);
	for(int i=1;i<=m;++i)printf("%I64d\n",q[i].ans);
	return 0;
}