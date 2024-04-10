#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=998244353;
const int inf=1e9;
bool v[2][N];
bool ck(int x){
	if(v[0][x]&&v[1][x])return 1;
	if(v[0][x+1]&&v[1][x+1])return 1;
	if(v[0][x]&&v[1][x+1])return 1;
	if(v[1][x]&&v[0][x+1])return 1;
	return 0;
}
int main(){int n,q,tot=0;
	scanf("%d%d",&n,&q);
	rep(i,1,q){int x,y;
		scanf("%d%d",&x,&y);
		if(y>1)tot-=ck(y-1);
		if(y<n)tot-=ck(y);
		v[x-1][y]^=1;
		if(y>1)tot+=ck(y-1);
		if(y<n)tot+=ck(y);
		printf("%s\n",tot?"No":"Yes");
	}
}