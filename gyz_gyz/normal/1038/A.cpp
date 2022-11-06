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
#define pb push_back
#define N 300000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define n2 500000004
#define eps 1e-8
using namespace std;
int n,k,ans,a[30];char s[N];
int main(){
	scanf("%d%d",&n,&k);scanf("%s",s+1);
	rep(i,1,n)a[s[i]-'A']++;ans=a[0];
	rep(i,1,k-1)if(a[i]<ans)ans=a[i];
	printf("%d",ans*k);
}