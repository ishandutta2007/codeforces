#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int sy,L,R,Q,s[N],n;
struct Seg{
	int l,r;	
}g[N];
inline double calc(int x,int y,int t){
	return 1.0*(t-x)*(sy+y)/y+x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(12);
	cin>>sy>>L>>R;
	cin>>n;
	sy=-sy;
	for(int i=1;i<=n;++i){
		cin>>g[i].l>>g[i].r;
		s[i]=s[i-1]+g[i].r-g[i].l;
	}
	cin>>Q;
	while(Q--){
		int x,y;
		cin>>x>>y;
		int l=1,r=n+1,ansl=n+1,ansr=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(calc(x,y,g[mid].l)>=L){
				ansl=r=mid;
			}
			else{
				l=mid+1;
			}	
		}		
		l=1,r=n+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(calc(x,y,g[mid].r)<=R){
				ansr=mid,l=mid+1;	
			}
			else{
				r=mid;
			}
		}
		double ans=ansl<=ansr?1.0*(s[ansr]-s[ansl-1])*(sy+y)/y:0;
		if(ansr<n)ans+=max(0.0,min(R*1.0,calc(x,y,g[ansr+1].r))-max(L*1.0,calc(x,y,g[ansr+1].l)));
		if(ansl>1&&ansl-1!=ansr+1)ans+=max(0.0,min(R*1.0,calc(x,y,g[ansl-1].r))-max(L*1.0,calc(x,y,g[ansl-1].l)));
		cout<<ans<<'\n';
	}
	return 0;
}