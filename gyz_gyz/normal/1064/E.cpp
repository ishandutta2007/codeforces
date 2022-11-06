#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 2010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,l,r,mid;char s[9],ss[9];
int main(){
	scanf("%d",&n);
	printf("0 0\n");l=2;r=inf-1;
	fflush(stdout);scanf("%s",ss);
	rep(i,2,n){
		mid=(l+r)/2;
		printf("%d 0\n",mid);
		fflush(stdout);scanf("%s",s);
		if(s[0]!=ss[0])r=mid-1;else l=mid+1;
	}
	printf("%d %d %d %d\n",l,1,inf,inf);
}