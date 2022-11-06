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
int n,a[30];char s[N];
int main(){
	scanf("%d",&n);scanf("%s",s);
	if(n==1){printf("Yes");return 0;}
	rep(i,0,n-1)a[s[i]-'a']++;
	rep(i,0,25)if(a[i]>1){printf("Yes");return 0;}
	printf("No");
}