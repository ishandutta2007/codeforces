#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
const ll inf=1e18+233;
int n;
ll a[N],ans;
void Solve(int L,int R){
	if(L==R){
		++ans;
		return;
	}
	int mid=(L+R)>>1;
	Solve(L,mid),Solve(mid+1,R);
	static ll pmn[N],pmx[N];
	static int s[N],jbmn[N],jbmx[N];
	static int h[N>>1][61];
	pmn[mid+1]=inf;
	pmx[mid+1]=-inf;
	for(int i=mid;i>=L;--i){
		pmn[i]=min(pmn[i+1],a[i]);
		pmx[i]=max(pmx[i+1],a[i]);
		jbmn[i]=__builtin_popcountll(pmn[i]);
		jbmx[i]=__builtin_popcountll(pmx[i]);
	}
	memset(h[mid+1-L+1],0,sizeof(h[mid+1-L+1]));
	for(int i=mid;i>=L;--i){
		memcpy(h[i-L+1],h[i-L+1+1],sizeof(h[i-L+1]));
		++h[i-L+1][jbmn[i]];
	}
	s[L-1]=0;
	for(int i=L;i<=mid;++i){
		s[i]=s[i-1]+(jbmn[i]==jbmx[i]);
	}
	ll gmn=inf,gmx=-inf;
	for(int i=mid+1,j1=mid+1,j2=mid+1;i<=R;++i){
		gmn=min(gmn,a[i]);
		gmx=max(gmx,a[i]);
		while(j1>L&&pmn[j1-1]>=gmn)--j1;
		while(j2>L&&pmx[j2-1]<=gmx)--j2;
		int cmn=__builtin_popcountll(gmn),cmx=__builtin_popcountll(gmx);
		if(cmn==cmx)ans+=mid+1-max(j1,j2);
		ans+=s[min(j1,j2)-1];
		if(j1>j2){
			ans+=h[j2-L+1][cmx]-h[j1-L+1][cmx];
		}
	}
	memset(h[mid+1-L+1],0,sizeof(h[mid+1-L+1]));
	for(int i=mid;i>=L;--i){
		memcpy(h[i-L+1],h[i-L+1+1],sizeof(h[i-L+1]));
		++h[i-L+1][jbmx[i]];
	}
	gmn=inf,gmx=-inf;
	for(int i=mid+1,j1=mid+1,j2=mid+1;i<=R;++i){
		gmn=min(gmn,a[i]);
		gmx=max(gmx,a[i]);
		while(j1>L&&pmn[j1-1]>=gmn)--j1;
		while(j2>L&&pmx[j2-1]<=gmx)--j2;
		int cmn=__builtin_popcountll(gmn);
		if(j1<j2){
			ans+=h[j1-L+1][cmn]-h[j2-L+1][cmn];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	Solve(1,n);
	cout<<ans<<'\n';
	return 0;
}