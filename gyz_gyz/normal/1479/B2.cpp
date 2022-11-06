#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
const ll inf=1e18;
int a[N],nt[N],v[N];
int main(){int n;
	scanf("%d",&n);nt[0]=n+2;
	rep(i,1,n){
		scanf("%d",&a[i]);v[i]=n+1;
	}
	dep(i,n,1){
		nt[i]=v[a[i]];v[a[i]]=i;
	}
	int x=0,y=0,ans=0;
	rep(i,1,n){
		if(a[i]==a[x])x=i;
		else if(a[i]==a[y])y=i;
		else{
			++ans;
			if(nt[x]>nt[y])x=i;else y=i;
		}
	}
	printf("%d\n",ans);
}