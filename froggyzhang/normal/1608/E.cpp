#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n;
class BIT{
	int Len;
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	void init(int _n){
		Len=_n;
		for(int i=1;i<=Len;++i)b[i]=0;
	}
	inline void Add(int x,int d){
		while(x<=Len)b[x]+=d,x+=lowbit(x);	
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B[3];
int x[N],y[N],c[N],bx[N],by[N],mx,my,p[N];
int D[N][3],U[N][3],L[N][3],R[N][3];
vector<int> X[N],Y[N];
int Get(int m,int c0,int c1){
	int l=1,r=m+1,mx=0;
	while(l<r){
		int mid=(l+r)>>1;
		int t0=B[c0].Ask(mid),t1=B[c1].Ask(m)-B[c1].Ask(mid);
		mx=max(mx,min(t0,t1));
		if(t0<=t1)l=mid+1;
		else r=mid;
	}
	return mx;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i]>>c[i];
		bx[i]=x[i],by[i]=y[i];
		--c[i];
	}
	sort(bx+1,bx+n+1);
	sort(by+1,by+n+1);
	mx=unique(bx+1,bx+n+1)-bx-1;
	my=unique(by+1,by+n+1)-by-1;
	for(int i=1;i<=n;++i){
		x[i]=lower_bound(bx+1,bx+mx+1,x[i])-bx;
		y[i]=lower_bound(by+1,by+my+1,y[i])-by;
		p[i]=i;
	}
	for(int i=1;i<=n;++i){
		X[x[i]].push_back(i);
		Y[y[i]].push_back(i);
	}
	{
		int now[3]={0,0,0};
		for(int i=1;i<=mx;++i){
			for(auto z:X[i]){
				now[c[z]]++;	
			}
			for(int j=0;j<3;++j)L[i][j]=now[j];
		}
	}
	{
		int now[3]={0,0,0};
		for(int i=mx;i>=1;--i){
			for(auto z:X[i]){
				now[c[z]]++;	
			}
			for(int j=0;j<3;++j)R[i][j]=now[j];
		}
	}
	{
		int now[3]={0,0,0};
		for(int i=1;i<=my;++i){
			for(auto z:Y[i]){
				now[c[z]]++;	
			}
			for(int j=0;j<3;++j)D[i][j]=now[j];
		}
	}
	{
		int now[3]={0,0,0};
		for(int i=my;i>=1;--i){
			for(auto z:Y[i]){
				now[c[z]]++;	
			}
			for(int j=0;j<3;++j)U[i][j]=now[j];	
		}
	}
	int ans=0;
	{	
		for(int i=0;i<3;++i)B[i].init(my);
		for(int i=1;i<=mx;++i){
			for(auto z:X[i]){
				B[c[z]].Add(y[z],1);
			}
			for(int j=0;j<3;++j){
				ans=max(ans,3*min(Get(my,(j+1)%3,(j+2)%3),R[i+1][j]));
				ans=max(ans,3*min(Get(my,(j+2)%3,(j+1)%3),R[i+1][j]));
			}
		}
	}
	{	
		for(int i=0;i<3;++i)B[i].init(my);
		for(int i=mx;i>=1;--i){
			for(auto z:X[i]){
				B[c[z]].Add(y[z],1);
			}
			for(int j=0;j<3;++j){
				ans=max(ans,3*min(Get(my,(j+1)%3,(j+2)%3),L[i-1][j]));
				ans=max(ans,3*min(Get(my,(j+2)%3,(j+1)%3),L[i-1][j]));
			}
		}
	}
	{	
		for(int i=0;i<3;++i)B[i].init(mx);
		for(int i=1;i<=my;++i){
			for(auto z:Y[i]){
				B[c[z]].Add(x[z],1);
			}
			for(int j=0;j<3;++j){
				ans=max(ans,3*min(Get(mx,(j+1)%3,(j+2)%3),U[i+1][j]));
				ans=max(ans,3*min(Get(mx,(j+2)%3,(j+1)%3),U[i+1][j]));
			}
		}
	}
	{	
		for(int i=0;i<3;++i)B[i].init(mx);
		for(int i=my;i>=1;--i){
			for(auto z:Y[i]){
				B[c[z]].Add(x[z],1);
			}
			for(int j=0;j<3;++j){
				ans=max(ans,3*min(Get(mx,(j+1)%3,(j+2)%3),D[i-1][j]));
				ans=max(ans,3*min(Get(mx,(j+2)%3,(j+1)%3),D[i-1][j]));
			}
		}
	}
	for(int i=0;i<3;++i)B[i].init(mx);
	for(int i=1;i<=n;++i){
		B[c[i]].Add(x[i],1);
	}
	for(int i=1;i<=mx;++i){
		int d[3]={0,1,2};
		do{
			ans=max(ans,3*min(R[i+1][d[2]],Get(i,d[0],d[1])));
		}while(next_permutation(d,d+3));
	}
	for(int i=0;i<3;++i)B[i].init(my);
	for(int i=1;i<=n;++i){
		B[c[i]].Add(y[i],1);
	}
	for(int i=1;i<=my;++i){
		int d[3]={0,1,2};
		do{
			ans=max(ans,3*min(U[i+1][d[2]],Get(i,d[0],d[1])));
		}while(next_permutation(d,d+3));
	}
	cout<<ans<<'\n';
	return 0;
}