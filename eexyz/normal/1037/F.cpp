#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define mod 1000000007
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int mx[N<<2],a[N],cnt,hd,s[N],t[N],st[N],l[N];
ll ans[N],ANS;
void build(int k,int l,int r){
	if(l==r)mx[k]=a[l];
	else build(ls,l,mid),build(rs,mid+1,r),mx[k]=max(mx[ls],mx[rs]);
}
int que(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)return mx[k];
	if(x>r||y<l)return 0;
	return max(que(ls,l,mid,x,y),que(rs,mid+1,r,x,y));
}
void cal(){
	hd=0;
	int L,i;
	for(i=1;i<=cnt;++i){
		L=1;
		while(hd&&s[st[hd]]<s[i]){
			L+=l[hd];--hd;
		}
		st[++hd]=i;l[hd]=L;
		ans[hd]=(ans[hd-1]+1ll*s[i]*L)%mod;
		(ANS+=ans[hd])%=mod;
	}
}
int n,k,i,j;
int main(){
	cin>>n>>k;
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,1,n);
	for(i=1;i<k;++i){
		cnt=0;
		for(j=i+k-1;j<=n;j+=k-1){
			s[++cnt]=que(1,1,n,j-k+1,j);
			t[cnt]=a[j];
		}
		cal();
	}
	cout<<ANS;
}