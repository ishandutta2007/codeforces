#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 100010
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n;char s[N];
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	rep(i,2,n)if(s[i]!=s[i-1]){
		printf("YES\n%c%c",s[i-1],s[i]);return 0;
	}
	printf("NO");
}