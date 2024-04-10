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
const int N=3e5+10;
const int mo=998244353;
int f[N];
int main(){int n;
	scanf("%d",&n);
	vector<pii>a,b;
	rep(i,1,n){int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)a.pb({x,i});else b.pb({x,i});
	}
	if(a.size()>b.size()){
		printf("%d\n",(int)a.size());
		sort(a.begin(),a.end());
		for(auto &i:a)printf("%d ",i.sc);
	}else{
		printf("%d\n",(int)b.size());
		sort(b.begin(),b.end(),[](pii a,pii b){return a>b;});
		for(auto &i:b)printf("%d ",i.sc);
	}
}