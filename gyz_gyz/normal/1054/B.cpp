#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define N 131072
#define ll long long
#define mo 1000000007
#define inf 1000000000
using namespace std;
int n,m,x;
int main(){
	scanf("%d",&n);m=-1;
	rep(i,1,n){
		scanf("%d",&x);
		if(x>m+1){
			printf("%d",i);return 0;
		}m=max(m,x);
	}
	printf("-1");
}