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
const int N=2e5+10;
const int mo=1e9+7;
bool a[N];
int sol(){int n,k;
	scanf("%d%d",&n,&k);
	if(k%3)return printf("%s\n",n%3?"Alice":"Bob");
	int s=n%(k+1);
	return printf("%s\n",s%3||s==k?"Alice":"Bob");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}