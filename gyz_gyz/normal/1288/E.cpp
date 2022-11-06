#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int mo=1e9+7;
const int inf=1e9;
const int N=6e5+10;
bool v[N];int n,m,a[N],ans[N],ls[N];
void f(int x,int y){
	for(;x<=n+m+1;x+=x&-x)a[x]+=y;
}
int q(int x){int r=0;
	for(;x;x-=x&-x)r+=a[x];return r;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		ls[i]=n-i+1;f(ls[i],1);
	}
	rep(i,1,m){int x;
		scanf("%d",&x);
		v[x]=1;ans[x]=max(ans[x],q(n+i)-q(ls[x])+1);
		f(ls[x],-1);ls[x]=n+i;f(ls[x],1);
	}
	rep(i,1,n)printf("%d %d\n",v[i]?1:i,max(ans[i],q(n+m+1)-q(ls[i])+1));
}