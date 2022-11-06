#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int N=4e6+10;
int f[N],t[2][N],h[N];
int main(){int n;
	scanf("%d",&n);
	int tot=1;h[1]=30;
	rep(i,1,n){int s;
		scanf("%d",&s);
		int x=1;
		dep(i,29,0){
			if(!t[(s>>i)&1][x]){
				t[(s>>i)&1][x]=++tot;
				h[tot]=i;
			}
			x=t[(s>>i)&1][x];
		}
	}
	dep(i,tot,1){
		if(!t[0][i]&&!t[1][i])f[i]=0;
		else if(!t[0][i])f[i]=f[t[1][i]];
		else if(!t[1][i])f[i]=f[t[0][i]];
		else f[i]=(1<<(h[i]-1))+min(f[t[0][i]],f[t[1][i]]);
	}
	printf("%d\n",f[1]);
}