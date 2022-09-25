#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,a[N],_l[N],_r[N],d[N];
void get_l(){
	static int st[N],top;
	st[0]=0;
	for(int i=1;i<=n+1;++i){
		while(2*d[st[top]]<a[i]-_l[st[top]]){
			--top;
		}
		_l[i]=a[st[top]];
		st[++top]=i;
	}
	if(top>1){
		cout<<0<<'\n';
		exit(0);
	}
}
void get_r(){
	static int st[N],top;
	st[0]=n+1;
	for(int i=n;i>=0;--i){
		while(2*d[st[top]]<_r[st[top]]-a[i]){
			--top;
		}
		_r[i]=a[st[top]];
		st[++top]=i;	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<=n+1;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>d[i];
	}
	d[0]=d[n+1]=inf;
	get_l();
	get_r();
	int ans=a[n+1];
	for(int i=1;i<=n+1;++i){
		static int st[N],top;
		if(2*d[i]>_r[i]-a[i]){
			auto Get=[&](int pos)->int{
				int l=0,r=top+1,jb=0;
				while(l<r){
					int mid=(l+r)>>1;
					if(2LL*d[st[mid]]>=1LL*pos-_l[st[mid]]){
						jb=mid;
						l=mid+1;
					}
					else{
						r=mid;
					}
				}
				return jb;
			};
			ans=min(ans,a[i]-a[st[Get(_r[i]-2*d[i])]]);
		}
		if(2*d[i]>a[i]-_l[i]){
			while(top&&2LL*d[i]+_l[i]>=2LL*d[st[top]]+_l[st[top]]){
				--top;
			}
			st[++top]=i;
		}
	}
	cout<<ans/2;
	if(ans&1)cout<<".5";
	return 0;
}