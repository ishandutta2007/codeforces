#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int mo=998244353;
struct str{
	string s;int hash=0;
	friend str&operator+=(str&a,const char&c){
		a.s+=c;a.hash=a.hash*2+(c-'0')%mo;return a;
	}
	friend bool operator==(const str&a,const str&b){
		return a.hash==b.hash&&a.s==b.s;
	}
}s[N];
int a[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){int x=-1;
		rep(j,1,i-1)s[i]+=a[j]>=i?'1':'0';
		rep(j,0,i-1)if(s[i]==s[j]){
			x=j;break;
		}
		int cnt=min(a[i],i);
		dep(j,i,0){
			if(cnt&&j!=x)--cnt,s[j]+='1';
			else s[j]+='0';
		}
	}
	printf("%d\n",n+1);
	rep(i,0,n)printf("%s\n",s[i].s.c_str());
}