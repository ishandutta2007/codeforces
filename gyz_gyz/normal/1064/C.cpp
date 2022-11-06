#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n;char s[N];
int main(){
	scanf("%d",&n);
	scanf("%s",s);sort(s,s+n);
	printf("%s",s);
}