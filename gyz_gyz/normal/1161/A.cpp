#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int inf=1e9;
int l[N],r[N];
int main(){int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,k){int x;
		scanf("%d",&x);
		if(!l[x])l[x]=i;
		r[x]=i;
	}int ans=0;
	rep(i,1,n){
		if(!l[i])++ans;
		if(i<n){
			if(!l[i]||!l[i+1]||l[i]>r[i+1])++ans;
			if(!l[i]||!l[i+1]||l[i+1]>r[i])++ans;
		}
	}
	printf("%d\n",ans);
}