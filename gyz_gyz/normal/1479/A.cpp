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
int n,a[N];
int q(int x){int y;
	if(x<1||x>n)return n+1;
	if(a[x])return a[x];
	printf("? %d\n",x);fflush(stdout);
	scanf("%d",&y);a[x]=y;return y;
}
int main(){
	scanf("%d",&n);
	int l=1,r=n;
	while(l<r){
		int m=(l+r)/2;
		int x=q(m),y=q(m-1),z=q(m+1);
		if(x<y&&x<z){
			printf("! %d\n",m);return 0;
		}
		if(x>y)r=m-1;else l=m+1;
	}
	printf("! %d\n",l);
}