#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
int a[N];
int main(){int n,D;
	scanf("%d%d",&n,&D);
	rep(i,1,n)scanf("%d",&a[i]);
	int t=0,m;scanf("%d",&m);
	rep(i,1,m){int x;
		scanf("%d",&x);
		while(t<n&&a[t+1]<x)++t;
		int md;
		if(!t)md=a[t+1]-x;
		else if(t==n)md=x-a[t]-1;
		else md=min(a[t+1]-x,x-a[t]-1);
		double ans=atan2(1,md);
		int l=t,r=t+1;
		while(l&&r<=n){
			double s=atan2(1,a[r]-x);
			while(l&&x-a[l]<a[r]-x){
				--l;if(s*2<=ans)break;
			}
			if(!l||s*2<=ans)break;
			if(x-a[l]-1<=a[r]-x){
				ans=s*2;break;
			}
			s=atan2(1,x-a[l]-1);
			while(r<=n&&a[r]-x+1<x-a[l]-1){
				++r;if(s*2<=ans)break;
			}
			if(r>n||s*2<=ans)break;
			if(a[r]-x<=x-a[l]-1){
				ans=s*2;break;
			}
		}
		printf("%.15lf\n",ans);		
	}
}