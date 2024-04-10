#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int n;char s[N];
int main(){int n,d=0;
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n){
		if(s[i]=='(')++d;
		printf("%d",d&1);
		if(s[i]==')')--d;
	}
}