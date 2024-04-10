#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define N 300010
#define mo 998244353
using namespace std;
typedef long long ll;
int main(){int n,p=0,q=0;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x>0)++p;
		if(x<0)++q;
	}
	printf("%d\n",p*2>=n?1:q*2>=n?-1:0);
}