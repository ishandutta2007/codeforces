#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
string s,s0,s1,s2,t;
int main(){
	cin>>s;t=s;int n=s.length();
	rep(i,0,n-1)s0+=i%26+'a';
	cout<<"? "<<s0<<'\n';fflush(stdout);cin>>s0;
	rep(i,0,n-1)s1+=(i/26)%26+'a';
	cout<<"? "<<s1<<'\n';fflush(stdout);cin>>s1;
	rep(i,0,n-1)s2+=(i/26/26)%26+'a';
	cout<<"? "<<s2<<'\n';fflush(stdout);cin>>s2;
	rep(i,0,n-1)t[(s0[i]-'a')+(s1[i]-'a')*26+(s2[i]-'a')*26*26]=s[i];
	cout<<"! "<<t<<'\n';fflush(stdout);
}