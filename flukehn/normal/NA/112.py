#include<bits/stdc++.h>
using namespace std;
const int N=5e5+11,oo=~0u>>2;
int n,a[N],b[N];
int work(int l,int r){
	if(a[l]>a[r]) return -1;
	int ret=0;
	for(int i=0;i<=r-l+1;++i)b[i]=oo;
	//int w=0;
	for(int i=l+1;i<r;++i){
		if(a[i]<a[l]||a[i]>a[r])++ret;
		else{
			*upper_bound(b,b+r-l,a[i])=a[i];
		}
	}
	return r-l-1-(lower_bound(b,b+r-l,oo)-b);
}
void merge(int &x,int y){
	if(x==-1||y==-1){
		x=-1;
		return;
	}
	x+=y;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int k;
	cin>>n>>k;
	a[0]=-oo;
	a[n+1]=oo;
	int lst=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]-=i;
	}
	int ans=0;
	for(int i=1;i<=k&&ans>=0;++i){
		int p;
		cin>>p;
		merge(ans,work(lst,p));
		lst=p;
	}
	merge(ans,work(lst,n+1));
	printf("%d\n",ans);
}
	//1019