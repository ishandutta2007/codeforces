#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
int main(){
	int n,m,ans=0;set<int>s;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m){int x;
		scanf("%d",&x);
		s.insert(x);
	}
	rep(i,1,n){
		auto x=s.lower_bound(a[i]);
		int ls=2e9;
		if(x!=s.end())ls=min(ls,*x-a[i]);
		if(x!=s.begin())ls=min(ls,a[i]-*--x);
		ans=max(ans,ls);
	}
	printf("%d\n",ans);
}