#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=4e5+10;
void sol(){int a,b,c,n;
	scanf("%d%d%d%d",&a,&b,&c,&n);
	int p=a+b+c+n;
	printf("%s\n",p%3||p/3<a||p/3<b||p/3<c?"NO":"YES");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}