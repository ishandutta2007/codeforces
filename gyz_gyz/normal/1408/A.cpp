#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int mo=1e9+7;
const ll inf=1e18;
int a[3][N],p[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,0,2)rep(j,1,n)scanf("%d",&a[i][j]);
	p[1]=a[0][1];
	rep(i,2,n-1){
		rep(j,0,2)if(a[j][i]!=p[i-1]){
			p[i]=a[j][i];break;
		}
	}
	rep(i,0,2)if(a[i][n]!=p[n-1]&&a[i][n]!=p[1]){
		p[n]=a[i][n];break;
	}
	rep(i,1,n)printf("%d%c",p[i],i==n?'\n':' ');
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}