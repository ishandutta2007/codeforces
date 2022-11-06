#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 1000000
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N],t[4];
int main(){int n;string s;
	scanf("%d",&n);cin>>s;
	rep(i,1,n)a[i]=s[i-1]-'0';
	rep(i,1,n)++t[a[i]];
	rep(i,1,n){
		if(a[i]&&t[0]<n/3&&t[a[i]]>n/3)s[i-1]='0',++t[0],--t[a[i]];
		else if(a[i]==2&&t[1]<n/3&&t[2]>n/3)s[i-1]='1',++t[1],--t[2];
	}
	dep(i,n,1){
		if(a[i]<2&&t[2]<n/3&&t[a[i]]>n/3)s[i-1]='2',++t[2],--t[a[i]];
		else if(!a[i]&&t[1]<n/3&&t[0]>n/3)s[i-1]='1',++t[1],--t[0];
	}
	cout<<s;
}