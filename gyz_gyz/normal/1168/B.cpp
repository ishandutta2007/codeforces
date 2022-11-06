#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=3e5+10;
const int inf=1e9;
char s[N];int a[N];
int main(){ll ans=0;
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n){
		a[i]=a[i-1];
		rep(j,1,n){
			if(i-j*2<=a[i-1])break;
			if(s[i]==s[i-j]&&s[i]==s[i-j*2]){
				a[i]=i-j*2;break;
			}
		}
		ans+=a[i];
	}
	printf("%lld\n",ans);
}