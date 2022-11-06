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
int s[N],t[N],w[N];
int main(){int L,R;
	scanf("%d%d",&L,&R);
	int n=22,m=0;
	rep(i,2,21){
		int nw=1;
		rep(j,1,i-1){
			s[++m]=j;t[m]=i;w[m]=nw;
			if(j>1)nw+=1<<(j-2);
		}
	}
	int nw=L,d=R-L;
	rep(i,1,21){
		if(i==1||(d>>(i-2))&1){
			s[++m]=i;t[m]=22;w[m]=nw;
			if(i>1)nw+=1<<(i-2);
		}
	}
	printf("YES\n%d %d\n",n,m);
	rep(i,1,m)printf("%d %d %d\n",s[i],t[i],w[i]);
}