#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int N=1e5+10;
void sol(){int x,y;
	scanf("%d%d",&x,&y);
	x=abs(x-y);int nw=0;
	rep(i,0,1000000000){
		nw+=i;
		if(nw>=x&&nw%2==x%2){
			printf("%d\n",i);return;
		}
	}
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}