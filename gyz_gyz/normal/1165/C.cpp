#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll Inf=1e18;
char s[N];
int main(){
	int n;string a;
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n)if(!(a.length()&1)||s[i]!=*(--a.end()))a+=s[i];
	if(a.length()&1)a.erase(--a.end());
	cout<<n-a.length()<<'\n'<<a<<'\n';
}