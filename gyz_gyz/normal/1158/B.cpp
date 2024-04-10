#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=3e5+10;
const int inf=1e9;
int n,m;char s[N];
bool dfs(int x){
	if(x>n){
		if(m>1)rep(i,m,x){bool eq=0;
			rep(j,m,x)if(i!=j){bool fl=1;
				rep(k,1,m-1)if(s[i-k]!=s[j-k]){
					fl=0;break;
				}
				if(fl){
					eq=1;break;
				}
			}
			if(!eq)return 0;
		}bool ok=(m==n);
		if(m<n)rep(i,m+1,x){bool eq=0;
			rep(j,m+1,x)if(i!=j){bool fl=1;
				rep(k,1,m)if(s[i-k]!=s[j-k]){
					fl=0;break;
				}
				if(fl){
					eq=1;break;
				}
			}
			if(!eq){
				ok=1;break;
			}
		}
		if(ok){
			printf("%s\n",s+1);return 1;
		}
		return 0;
	}
	s[x]='0';if(dfs(x+1))return 1;
	s[x]='1';if(dfs(x+1))return 1;return 0;
}
int main(){
	/*rep(i,1,20)rep(j,1,i)if(i%2==j%2){
		n=i;m=j;printf("%d,%d:",i,j);dfs(1);
	}*/
	scanf("%d%d",&n,&m);
	if(m==1){
		rep(i,1,n-1)printf("0");
		printf("1");
		return 0;
	}
	if(m+(m-2)*2<=n){
		rep(i,1,m-2)printf("0");
		printf("1");
		rep(i,1,m-2)printf("0");
		printf("1");
		rep(i,m*2-1,n)printf("0");return 0;
	}
	rep(i,1,n)if(n-m<=(i-1)*2){
		int t1=min(n-m,i-1);
		rep(j,1,t1)s[j]='0';
		if(t1<n)s[t1+1]='1';
		rep(j,t1+2,n)s[j]=s[j-i];
		printf("%s",s+1);return 0;
	}
	
}