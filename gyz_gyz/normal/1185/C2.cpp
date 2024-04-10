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
const int N=2e6+10;
const int mo=998244353;
int main(){int n,m,nw=0;
	scanf("%d%d",&n,&m);multiset<int>s;
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(m>=x)printf("%d ",nw);else{int ct=0,rs=0;
			for(auto i=s.rbegin();m+rs<x;rs+=*(i++))++ct;
			printf("%d ",nw+ct);
		}
		s.insert(x);
		for(m-=x;m<0;++nw){
			m+=*s.rbegin();s.erase(--s.end());
		}
	}
}