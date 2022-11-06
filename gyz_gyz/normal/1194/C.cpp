#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
int ct[26];
int sol(){string s,t,p;
	cin>>s>>t>>p;
	rep(i,0,25)ct[i]=0;
	for(auto &i:s)++ct[i-'a'];
	for(auto &i:p)++ct[i-'a'];
	for(auto &i:t)if(!ct[i-'a']--)return printf("NO\n");
	int n=t.length(),x=0;
	for(auto &i:s){
		while(x<n&&t[x]!=i)++x;
		if(x>=n)return printf("NO\n");++x;
	}printf("YES\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}