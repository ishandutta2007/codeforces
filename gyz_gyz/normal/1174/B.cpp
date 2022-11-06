#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int a[N];
int main(){int n;bool fl1=0,fl2=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]&1)fl1=1;else fl2=1;
	}
	if(fl1&&fl2)sort(a+1,a+n+1);
	rep(i,1,n)printf("%d ",a[i]);
}