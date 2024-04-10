#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
void sol(){int n;
	scanf("%d",&n);
	bool fl=0;
	string S,s;cin>>S;
	for(auto i:S){
		if(i=='8')fl=1;
		if(fl)s+=i;
	}
	printf("%s\n",s.length()>=11?"YES":"NO");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}