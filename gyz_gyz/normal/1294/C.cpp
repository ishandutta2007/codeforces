#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=4e5+10;
int v[3];
void sol(){int n;
	scanf("%d",&n);
	int tot=0;
	rep(i,2,n){
		if(i*i>=n)break;
		if(!(n%i)){
			n/=i;v[tot++]=i;
			if(tot>=2){
				v[tot++]=n;break;
			}
		}
	}
	if(tot<3){
		printf("NO\n");return;
	}
	printf("YES\n%d %d %d\n",v[0],v[1],v[2]);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}