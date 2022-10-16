#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N],m,Ans[N];
bool check(int t){
	int zz=0;
	for(int i=1;i<=n;++i)Ans[i]=0;
	for(int i=1;i<=n;++i){
		if(a[i]<=m){
			++zz;
			Ans[i]=1;
		}
	}
	if(zz>=t)return true;
	int rem=t-zz,pos=0;
	for(int i=n;i>=1;--i){
		if(a[i]>m){
			--rem;
			if(!rem){
				pos=i;
				break;
			}
		}
	}
	int now=m;
	for(int i=pos;i<=n;++i){
		if(a[i]>now){
			if(!now)return false;
			--now;
		}
	}
	for(int i=1;i<pos;++i){
		if(a[i]<=m)Ans[i]=1;
		else Ans[i]=0;
	}
	for(int i=pos;i<=n;++i)Ans[i]=1;
	return true;
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int l=0,r=n+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,l=mid+1;
		}
		else{
			r=mid;
		}
	}
	check(ans);
	for(int i=1;i<=n;++i){
		cout<<Ans[i];
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}