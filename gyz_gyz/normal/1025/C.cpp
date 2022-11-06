#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 300010
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,x,ans;char s[N];
int main(){
	scanf("%s",s);while(s[n])n++;
	rep(i,0,n-1)s[n+i]=s[i];ans=x=1;
	rep(i,1,n*2-1)if(s[i]!=s[i-1])x++;else{
		if(x>ans)ans=x;x=1;
	}
	if(x>ans)ans=x;if(ans>n)ans=n;
	printf("%d",ans);
}