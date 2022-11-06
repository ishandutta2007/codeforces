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
const int N=3e5+10;
int a[N][9],b[300],c[300];
int main(){int n,m,ans=-1,an1,an2;
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
	rep(i,0,(1<<m)-1){b[i]=-1;
		rep(j,1,n){int x=inf;
			rep(k,1,m)if((i>>(k-1))&1)x=min(x,a[j][k]);
			if(x>b[i])b[i]=x,c[i]=j;
		}
	}
	rep(i,0,(1<<m)-1)if(min(b[i],b[((1<<m)-1)^i])>ans){
		ans=min(b[i],b[((1<<m)-1)^i]);
		an1=c[i];an2=c[((1<<m)-1)^i];
	}
	printf("%d %d\n",an1,an2);
}