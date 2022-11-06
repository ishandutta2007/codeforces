#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=510;
const int inf=1e9;
const int mo=998244353;
int f[N][N],s[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&f[i][i]);
	rep(i,1,n-1)rep(j,1,n-i){f[j][j+i]=-1;
		rep(k,0,i-1)if(~f[j][j+k]&&f[j][j+k]==f[j+k+1][j+i]){
			f[j][j+i]=f[j][j+k]+1;break;
		}
	}
	rep(i,1,n){s[i]=inf;
		rep(j,0,i-1)if(~f[j+1][i])s[i]=min(s[i],s[j]+1);
	}
	printf("%d\n",s[n]);
}