#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=1e9+7;
int a[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	bool f0=0,f1=0,fl=1;
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(i>1&&a[i]<a[i-1])fl=0;
		if(x)f1=1;else f0=1;
	}
	printf("%s\n",fl||(f0&&f1)?"Yes":"No");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}