#include<bits/stdc++.h>
using namespace std;
#define N 400010
typedef long long ll;
int n,a[N],b[N],len,ans;
class BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	void Add(int x,int d){
		while(x<=len)b[x]=max(b[x],d),x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans=max(ans,b[x]),x-=lowbit(x);
		return ans;
	}
}B0,B1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]-=i;
		b[++len]=a[i];
		b[++len]=a[i]+1;
	}
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b+1,b+len+1,a[i])-b;
	}
	for(int i=1,t0,t1;i<=n;++i){
		t1=max(B1.Ask(a[i])+1,B0.Ask(a[i]+1)+1);
		if(i>1)B0.Add(a[i-1],t0);
		t0=B0.Ask(a[i])+1;
		ans=max(ans,max(t0,t1));
		B1.Add(a[i],t1);
	}
	cout<<max(n-1-ans,0)<<'\n';
	return 0;
}