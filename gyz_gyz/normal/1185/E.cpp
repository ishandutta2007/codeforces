#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<pii,pii>ppp;
const int N=2e3+10;
const ll inf=2e18;
char s[N][N];int ct[30];
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,25)ct[i]=0;
	stack<ppp>res;
	rep(i,1,n){
		scanf("%s",s[i]+1);
		rep(j,1,m)if(s[i][j]>='a'&&s[i][j]<='z')++ct[s[i][j]-'a'];
	}
	dep(k,25,0)if(ct[k]){
		rep(i,1,n)rep(j,1,m)if(s[i][j]-'a'==k){int rs=m;
			rep(l,j,m)if(s[i][l]-'a'==k)--ct[k];
			else if(s[i][l]){rs=l-1;break;}
			if(!ct[k]){
				rep(l,j,rs)if(s[i][l]-'a'==k)s[i][l]=0;
				res.push({{i,j},{i,rs}});break;
			}
			rep(l,j,rs)if(s[i][l]-'a'==k)++ct[k];rs=n;
			rep(l,i,n)if(s[l][j]-'a'==k)--ct[k];
			else if(s[l][j]){rs=l-1;break;}
			if(!ct[k]){
				rep(l,i,rs)if(s[l][j]-'a'==k)s[l][j]=0;
				res.push({{i,j},{rs,j}});break;
			}
			printf("NO\n");return;
		}
	}else if(!res.empty())res.push(res.top());
	printf("YES\n");
	printf("%d\n",(int)res.size());
	for(;!res.empty();res.pop())
		printf("%d %d %d %d\n",res.top().fr.fr,res.top().fr.sc,res.top().sc.fr,res.top().sc.sc);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}