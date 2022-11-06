#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 2000
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,i1,i2;string s[N],s1,s2;bool v[N];
bool hz(string s,string t){
	int l1=s.length(),l2=t.length();
	rep(i,1,l1)if(s[l1-i]!=t[l2-i])return 0;return 1;
}
bool qz(string s,string t){
	int l1=s.length();
	rep(i,0,l1-1)if(s[i]!=t[i])return 0;return 1;
}
void tr2(){string r="";
	rep(i,1,n-1)v[i]=0;
	rep(i,1,n*2-2)if(qz(s[i],s2)){
		int l=s[i].length();
		if(v[l]){
			if(hz(s[i],s2))r+='S';else return;
		}else v[l]=1,r+='P';
	}else if(hz(s[i],s2))r+='S';else return;
	cout<<r;exit(0);
}
void tr1(){string r="";
	rep(i,1,n-1)v[i]=0;
	rep(i,1,n*2-2)if(qz(s[i],s1)){
		int l=s[i].length();
		if(v[l]){
			if(hz(s[i],s1))r+='S';else return;
		}else v[l]=1,r+='P';
	}else if(hz(s[i],s1))r+='S';else return;
	cout<<r;exit(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n*2-2){
		cin>>s[i];
		if(s[i].length()==n-1){
			if(!i1)i1=i;else i2=i;
		}
	}
	s1=s[i1]+s[i2][n-2],s2=s[i2]+s[i1][n-2];
	tr1();tr2();
}