#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
char a[N];
void sol(){
	scanf("%s",a+1);
	int n=strlen(a+1),mx=0;
	while(mx+1<n-mx&&a[mx+1]==a[n-mx])++mx;
	int l=mx,r=n-mx+1;
	dep(i,n-mx,mx+1){bool fl=1;
		rep(j,mx+1,i)if(a[j]!=a[i-j+mx+1]){
			fl=0;break;
		}
		if(fl){
			l=i;break;
		}
	}
	rep(i,mx+1,n-mx){bool fl=1;
		rep(j,i,n-mx)if(a[j]!=a[i-j+n-mx]){
			fl=0;break;
		}
		if(fl){
			r=i;break;
		}
	}
	if(l+mx>=n-r+1+mx){
		rep(i,1,l)printf("%c",a[i]);
		rep(i,n-mx+1,n)printf("%c",a[i]);
	}else{
		rep(i,1,mx)printf("%c",a[i]);
		rep(i,r,n)printf("%c",a[i]);
	}printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}