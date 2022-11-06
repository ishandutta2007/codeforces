#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=998244353;
const ll inf=1e18;
char s[N];int a[N];
void sol(){
	int n,k,tot=0,tt=0,ans=0;bool fl=0;
	scanf("%d%d%s",&n,&k,s+1);
	rep(i,1,n){
		if(s[i]=='L')++tt;
		else{
			++ans;
			if(s[i-1]=='W')++ans;
			else if(fl)a[++tot]=tt;
			fl=1;tt=0;
		}
	}
	if(tot)sort(a+1,a+tot+1);
	rep(i,1,tot){
		if(k<a[i])break;
		ans+=a[i]*2+1;k-=a[i];
	}
	if(!fl&&k)--k,++ans;
	ans+=k*2;
	printf("%d\n",min(ans,n*2-1));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}