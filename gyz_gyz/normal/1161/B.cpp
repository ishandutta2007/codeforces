#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int inf=1e9;
int main(){int n,m;
	scanf("%d%d",&n,&m);
	set<pair<int,int>>s;
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		s.insert({x,y});
	}
	rep(i,1,n-1)if(!(n%i)){bool fl=1;
		for(auto&j:s){
			pii r={(j.fr+i-1)%n+1,(j.sc+i-1)%n+1};
			if(r.fr>r.sc)swap(r.fr,r.sc);
			if(!s.count(r)){
				fl=0;break;
			}
		}
		if(fl){
			printf("Yes\n");return 0;
		}
	}
	printf("No\n");
}