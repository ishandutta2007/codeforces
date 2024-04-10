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
#define N 20010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[26],b[26];
int main(){int n,ans=0;
	scanf("%d",&n);
	while(n--){string s;
		cin>>s;int m=s.length()-1,l=1,r=1;bool fl=1;
		rep(i,0,m)s[i]-='a';
		rep(i,0,25)b[i]=0;b[s[0]]=1;
		rep(i,1,m){
			if(s[i]==s[i-1]){
				if(fl)++l;++r;
			}else fl=0,r=1;
			b[s[i]]=max(b[s[i]],r);
		}
		if(r==m+1)b[s[0]]+=a[s[0]]*(b[s[0]]+1);
		if(s[0]==s[m]&&a[s[0]])b[s[0]]=max(b[s[0]],l+r+1);
		if(a[s[0]])b[s[0]]=max(b[s[0]],l+1);
		if(a[s[m]])b[s[m]]=max(b[s[m]],r+1);
		rep(i,0,25)a[i]=max(int(a[i]>0),b[i]);
	}
	rep(i,0,25)ans=max(ans,a[i]);
	printf("%d\n",ans);
}