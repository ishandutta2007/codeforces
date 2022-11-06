#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int mo=1e9+7;
const ll Inf=1e18;
char a[N][N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",a[i]+1);
	int i1=n,i2=0,i3,j1=m,j2=0,j3,ct=0;
	rep(i,1,n)rep(j,1,m)if(a[i][j]=='*'){++ct;
		if(i<i1)i1=i,j3=j;
		if(j<j1)j1=j,i3=i;
		i2=max(i2,i);j2=max(j2,j);
	}
	if(ct+1!=(i2-i1+1)+(j2-j1+1)||i3<=i1||i3>=i2||j3<=j1||j3>=j2)return printf("NO\n"),0;
	rep(i,i1,i2)if(a[i][j3]!='*')return printf("NO\n"),0;
	rep(j,j1,j2)if(a[i3][j]!='*')return printf("NO\n"),0;
	printf("YES\n");
}