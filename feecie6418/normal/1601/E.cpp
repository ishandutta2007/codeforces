#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Query{
	int l,r,id;
};
int a[300005],n,m,K,st[300005],top,val[300005];
ll ans[300005],sum[300005];
vector<Query> rema[300005],q[300005];
int f[20][300005],lg2[300005]={-1};
int Q(int l,int r){
	if(l>n)return 0;
	r=min(r,n);
	int k=lg2[r-l+1];
	return min(f[k][l],f[k][r-(1<<k)+1]);
}
void Solve(int rem){
	if(!rema[rem].size())return ;
	for(auto i:rema[rem])q[i.r/K].push_back(i);
	//[rem,rem+K-1],[rem+K,rem+2K-1]...
	top=0;
	for(int i=0,w=n/K;i<=w;i++){
		//cout<<"I:"<<i<<'\n';
		for(auto j:q[i]){
			ans[j.id]=a[j.r];
			if(j.l==j.r)continue;
			//cout<<"Answering! "<<j.id<<'\n';
			//for(int k=1;k<=top;k++)cout<<k<<' '<<st[k]<<' '<<val[st[k]]<<'\n';
			int l=1,r=top,pp=top+1;
			while(l<=r){
				int mid=(l+r)/2;
				if(val[st[mid]]>=a[j.r])pp=mid,r=mid-1;
				else l=mid+1;
			}
			//[pp,top]:>=a[j.r]
			//lval[l/K]
			int pos=lower_bound(st+1,st+top+1,j.l/K)-st;
			//[pos,pp):
			if(pp>pos){
				ans[j.id]+=1ll*a[j.r]*(i-st[min(pp-1,top)]-1);
				ans[j.id]+=sum[min(pp-1,top)]-sum[pos];
				ans[j.id]+=1ll*val[st[pos]]*(st[pos]-j.l/K+1);
			}
			else ans[j.id]+=1ll*a[j.r]*(i-j.l/K);
		}
		val[i]=Q(rem+i*K,rem+(i+1)*K-1);
		while(top&&val[st[top]]>=val[i])top--;
		st[++top]=i,sum[top]=sum[top-1]+1ll*val[i]*(st[top]-st[top-1]);
		q[i].clear();
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)f[0][i]=a[i],lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=18;i++)for(int j=1;j+(1<<i)-1<=n;j++)f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		l=n-l+1,r=n-r+1,swap(l,r),l=r-(r-l)/K*K;
		rema[l%K].push_back({l,r,i});
	}
	for(int i=0;i<K;i++)Solve(i);
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
}