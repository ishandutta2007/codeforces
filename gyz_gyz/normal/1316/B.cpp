#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
void sol(){int n;string s;
	scanf("%d",&n);
	cin>>s;string ans=s;int k=1;
	rep(i,2,n){
		string t,t1;
		rep(j,1,n)if(j<i)t1+=s[j-1];else t+=s[j-1];
		if((i&1)==(n&1))reverse(t1.begin(),t1.end());
		t+=t1;
		if(t<ans)ans=t,k=i;
	}
	printf("%s\n%d\n",ans.c_str(),k);	
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}