#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=998244353;
int a[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	if(!(n&1)){
		rep(i,1,n)printf("%d ",a[i]>=0?-a[i]-1:a[i]);
	}else{
		int mx=0,x=0,mi=-1,y=0;
		rep(i,1,n){
			if(a[i]<0){
				if(-a[i]>mx)mx=-a[i],x=i;
			}else{
				if(a[i]>mi)mi=a[i],y=i;
			}
		}
		if(x&&(mi<mx||!y))rep(i,1,n)printf("%d ",a[i]>=0||i==x?-a[i]-1:a[i]);
		else rep(i,1,n)printf("%d ",a[i]>=0&&i!=y?-a[i]-1:a[i]);
	}
}