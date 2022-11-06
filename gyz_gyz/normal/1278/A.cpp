#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int N=1e5+10;
char a[N],b[N];int cnt[N];
bool sol(){
	scanf("%s%s",a+1,b+1);
	int n=strlen(a+1),m=strlen(b+1);
	rep(i,1,m-n+1){
		rep(j,0,25)cnt[j]=0;
		rep(j,1,n)++cnt[a[j]-'a'];
		rep(j,i,i+n-1)--cnt[b[j]-'a'];
		bool fl=1;
		rep(j,0,25)if(cnt[j]){
			fl=0;break;
		}
		if(fl)return 1;
	}
	return 0;
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)printf("%s\n",sol()?"YES":"NO");
}