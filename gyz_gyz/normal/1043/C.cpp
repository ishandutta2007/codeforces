#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,w[N];string s;
int main(){
	cin>>s;n=s.length();
	rep(i,1,n-1)if(s[i]=='a')w[i-1]^=1,w[i]^=1;
	rep(i,0,n-1)printf("%d ",w[i]);
}