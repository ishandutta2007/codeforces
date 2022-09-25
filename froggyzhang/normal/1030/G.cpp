#include<bits/stdc++.h>
using namespace std;
#define N 2000200
typedef long long ll;
const int mod=1e9+7;
const int B=2000000;
int low[N],n,a[N],mx[N],cnt[N],jb[N],ans,vis[N];
inline void update(int p,int x){
	if(x>mx[p])mx[p]=x,cnt[p]=1;
	else cnt[p]+=mx[p]==x;	
}
bool check(int x){
	while(x>1){
		int p=low[x],c=0;
		while(low[x]==p)x/=low[x],++c;
		if(mx[p]==c&&cnt[p]==1)return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=2;i<=B;++i){
		if(!low[i]){
			for(int j=i;j<=B;j+=i){
				if(!low[j])low[j]=i;	
			}
		}	
	}
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i){
		if(mx[a[i]]){
			int x=a[i]-1;
			while(x>1){
				int p=low[x],c=0;
				while(low[x]==p)x/=low[x],++c;
				update(p,c);	
			}
			vis[i]=1;
		}
		else{
			update(a[i],1);
		}
	}
	int flag=0;
	for(int i=1;i<=n;++i){
		if(vis[i]&&check(a[i]-1)){flag=1;break;}	
	}
	ans=1;
	for(int i=2;i<=B;++i){
		while(mx[i]--)ans=1LL*ans*i%mod;
	}
	cout<<(ans+flag)%mod;
	return 0;
}