#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
ll s[N],x;
void Solve(){
	cin>>n>>x;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	static int st[N],top;
	top=0;
	pair<int,int> ans=make_pair(0,0); 
	for(int i=n;i>=1;--i){
		while(top&&s[i]<=s[st[top]])--top;
		st[++top]=i;
		int pos=n;
		int l=1,r=top+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(s[st[mid]]-s[i-1]<-x){
				pos=st[mid]-1;
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		ans=max(ans,make_pair(pos-i+1,i));
	}
	if(!ans.first){
		cout<<-1<<'\n';
	}
	else{
		cout<<ans.second<<' '<<ans.first+ans.second-1<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}