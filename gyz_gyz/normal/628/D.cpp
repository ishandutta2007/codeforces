#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define mo 1000000007
using namespace std;
typedef long long ll;
int n,m;ll a[2][2010];
ll cal(string s){
	int l=s.length()-1,tt=0;bool t=0,fl=1;
	rep(i,0,n-1)a[0][i]=a[1][i]=0;
	rep(i,0,l){t^=1;
		rep(j,0,n-1)a[t][j]=0;
		rep(k,0,9)if(t^(k==m)){
			rep(j,0,n-1)add(a[t][(j*10+k)%n],a[t^1][j]);
			if(fl&&(k||i)&&k<s[i]-'0')add(a[t][(tt*10+k)%n],1);
		}
		if(!(t^(s[i]-'0'==m)))fl=0;
		tt=(tt*10+s[i]-'0')%n;
	}return a[t][0];
}
void ad(string &s){
	++s[s.length()-1];
	dep(i,s.length()-1,1)
		if(s[i]>'9')++s[i-1],s[i]='0';else break;
}
int main(){
	scanf("%d%d",&n,&m);string s;
	cin>>s;ll ans=(mo-cal(s))%mo;
	cin>>s;ad(s);add(ans,cal(s));
	printf("%lld\n",ans);
}