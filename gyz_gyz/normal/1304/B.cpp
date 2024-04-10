#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int mo=1e9+7;
const int inf=1e9;
string s[N];bool ok[N][N],v[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)cin>>s[i];
	rep(i,1,n)rep(j,1,n){ok[i][j]=1;
		rep(k,1,m)if(s[i][k-1]!=s[j][m-k]){
			ok[i][j]=0;break;
		}
	}
	string res;
	rep(i,1,n)if(ok[i][i]==1){
		v[i]=1;res=s[i];break;
	}
	rep(i,1,n)if(!v[i]){
		rep(j,i+1,n)if(ok[i][j]){
			v[i]=v[j]=1;res=s[i]+res+s[j];
		}
	}
	printf("%d\n%s\n",(int)res.length(),res.c_str());
}