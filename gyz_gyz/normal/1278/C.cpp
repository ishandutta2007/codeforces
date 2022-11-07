#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int N=1e5+10;
int a[N],b[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	map<int,int>mp;int ans=n*2;
	rep(i,0,n){
		if(!i)a[i]=0;
		else if(a[i]==1)a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
		mp[a[i]]=n-i;
	}
	dep(i,n+1,1){
		if(i==n+1)b[i]=0;
		else if(b[i]==2)b[i]=b[i+1]+1;
		else b[i]=b[i+1]-1;
		if(mp.count(b[i]))ans=min(ans,i-1+mp[b[i]]);
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}