#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005],s[100005],sk[100005],tot,ls[4000005],rs[4000005],root,root2;
ll minn[4000005];
map<int,int> mp;
void Update(int &p,ll l,ll r,ll x,ll y){
	if(!p)p=++tot,minn[p]=1e18;
	minn[p]=min(minn[p],y);
	if(l==r)return ;
	ll mid=(l+r)/2;
	if(x>mid)Update(rs[p],mid+1,r,x,y);
	else Update(ls[p],l,mid,x,y);
}
ll Q(int p,ll l,ll r,ll x,ll y){
	if(!p)return 1e18;
	if(x<=l&&r<=y)return minn[p];
	ll mid=(l+r)/2,mx=1e18;
	if(y>mid)mx=min(mx,Q(rs[p],mid+1,r,x,y));
	if(x<=mid)mx=min(mx,Q(ls[p],l,mid,x,y));
	return mx;
}
namespace T2{
ll minn[4000005];
int tot,ls[4000005],rs[4000005];
void Update(int &p,ll l,ll r,ll x,ll y){
	if(!p)p=++tot,minn[p]=-1e9;
	minn[p]=max(minn[p],y);
	if(l==r)return ;
	ll mid=(l+r)/2;
	if(x>mid)Update(rs[p],mid+1,r,x,y);
	else Update(ls[p],l,mid,x,y);
}
ll Q(int p,ll l,ll r,ll x,ll y){
	if(!p)return -1e9;
	if(x<=l&&r<=y)return minn[p];
	ll mid=(l+r)/2,mx=-1e9;
	if(y>mid)mx=max(mx,Q(rs[p],mid+1,r,x,y));
	if(x<=mid)mx=max(mx,Q(ls[p],l,mid,x,y));
	return mx;
}
void Clear(){
	for(int i=1;i<=tot;i++)ls[i]=rs[i]=0,minn[i]=-1e9;
	tot=root2=0;
}}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("2.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,K;
		cin>>n>>K,mp.clear(),tot=0,root=0,s[0]=sk[0]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),mp[a[i]]++;
		if(!mp[K]){
			puts("No");
			continue;
		}
		if(n==1){
			puts("Yes");
			continue;
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+(a[i]<=K),sk[i]=sk[i-1]+(a[i]==K);
			if(Q(root,1,1e7,i+1-2*s[i]+5e6,1e7)<i+1+2*sk[i]-2*s[i])flag=1;
			Update(root,1,1e7,i-2*s[i-1]+5e6,-2*s[i-1]+2*sk[i-1]+i);
		}
		if(flag){puts("Yes");
		for(int i=1;i<=tot;i++)ls[i]=rs[i]=0,minn[i]=1e18;
		continue;
		}
		//*2<n*2>=n
		if(s[n]*2<n){
			puts("Yes");
			for(int i=1;i<=tot;i++)ls[i]=rs[i]=0,minn[i]=1e18;
			continue;
		}
		int minlen=1e9,pp=1e9;
		for(int i=1;i<=n;i++){
			int maxl=T2::Q(root2,1,1e7,2*s[i]-i+1+5e6,1e7);
			minlen=min(minlen,i-maxl+1);
			//cout<<maxl<<endl;
			if(maxl>0)pp=min(pp,s[i]-s[maxl-1]);
			T2::Update(root2,1,1e7,-i+1+2*s[i-1]+5e6,i);
		}
		if((s[n]-pp)*2>=n)puts("Yes");
		else puts("No");
		for(int i=1;i<=tot;i++)ls[i]=rs[i]=0,minn[i]=1e18;
		T2::Clear();
	}
	return 0;
}