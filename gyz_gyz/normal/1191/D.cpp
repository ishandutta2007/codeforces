#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
int a[N];
int main(){int n,ans=0,x=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,2,n)if(a[i]==a[i-1]){
		if(x)return printf("cslnb"),0;else x=i-1;
	}
	if(x&&((!a[x])||(x>1&&a[x]-1==a[x-1])))return printf("cslnb"),0;
	rep(i,1,n)ans^=(a[i]-(i-1))&1;
	printf("%s\n",ans?"sjfnb":"cslnb");
}