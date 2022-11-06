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
const int N=2e6+10;
const int mo=998244353;
bool sol(){string s1,s2;
	cin>>s1>>s2;int x=0;
	for(auto &i:s1){
		for(;x<s2.length()&&i!=s2[x];++x)
			if(!x||s2[x]!=s2[x-1])return 0;
		if(x>=s2.length())return 0;++x;
	}
	while(x<s2.length()&&s2[x]==s2[x-1])++x;
	return x>=s2.length();
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)printf("%s\n",sol()?"YES":"NO");
}