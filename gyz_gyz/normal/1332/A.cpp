#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1010;
const int inf=1e9;
const int mo=998244353;
bool sol(){int a,b,c,d,x,y,x1,y1,x2,y2;
	scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&x,&y,&x1,&y1,&x2,&y2);
	if((a||b)&&x==x1&&x==x2)return 0;
	if((c||d)&&y==y1&&y==y2)return 0;
	if(x-a+b<x1||x-a+b>x2)return 0;
	if(y-c+d<y1||y-c+d>y2)return 0;
	return 1;
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)printf("%s\n",sol()?"Yes":"No");
}