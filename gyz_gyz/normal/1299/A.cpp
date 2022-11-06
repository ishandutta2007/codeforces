#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
int a[N],v[33];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		rep(j,0,30)if((a[i]>>j)&1)++v[j];
	}
	int p=0,s=-1;
	rep(i,1,n){
		int x=0;
		rep(j,0,30)if(v[j]==1&&((a[i]>>j)&1))x+=1<<j;
		if(x>s)s=x,p=i;
	}
	printf("%d",a[p]);
	rep(i,1,n)if(i!=p)printf(" %d",a[i]);
	printf("\n");
}