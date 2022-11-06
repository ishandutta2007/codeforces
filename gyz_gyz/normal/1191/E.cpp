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
int a[N],b[N];char s[N];
int main(){int n,k;
	scanf("%d%d",&n,&k);
	set<int>p0,p1;
	scanf("%s",s+1);
	rep(i,1,n){
		if(s[i]=='0')p0.insert(i);else p1.insert(i);
		a[i]=a[i-1]+(s[i]=='0');
		b[i]=b[i-1]+(s[i]=='1');
	}
	rep(i,k,n)if(a[i]-a[i-k]==a[n]||b[i]-b[i-k]==b[n])
		return printf("tokitsukaze\n"),0;
	rep(i,k,n){
		int l=*p0.begin(),r=*--p0.end();
		if(l>i-k&&l<=i)l=*p0.upper_bound(i);
		if(r>i-k&&r<=i)r=*--p0.upper_bound(i-k);
		if(r-l+1>k)return printf("once again\n"),0;
 		l=*p1.begin(),r=*--p1.end();
		if(l>i-k&&l<=i)l=*p1.upper_bound(i);
		if(r>i-k&&r<=i)r=*--p1.upper_bound(i-k);
		if(r-l+1>k)return printf("once again\n"),0;
	}
	printf("quailty\n");
}