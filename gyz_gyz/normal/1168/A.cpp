#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=3e5+10;
const int inf=1e9;
int n,m,a[N],b[N];
bool ck(int k){
	rep(i,1,n){
		if(b[i-1]+m-a[i]<=k)b[i]=b[i-1];
		else if(b[i-1]-a[i]<=k)b[i]=max(a[i],b[i-1]);
		else return 0;
	}return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	int l=0,r=m,mid=(l+r)>>1;
	for(;l<r;mid=(l+r)>>1)
		if(ck(mid))r=mid;else l=mid+1;
	printf("%d\n",mid);
}