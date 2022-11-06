#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=110;
struct str{
	int v[26];
	str(){memset(this,0,sizeof(str));}
	void clear(){memset(this,0,sizeof(str));}
	int count(){int cnt=0;
		rep(i,0,25)cnt+=v[i];return cnt;
	}
	friend str operator +(str a,const str&b){
		rep(i,0,25)a.v[i]+=b.v[i];return a;
	}
	friend str&operator +=(str&a,const str&b){
		rep(i,0,25)a.v[i]+=b.v[i];return a;
	}
	friend str operator -(str a,const str&b){
		rep(i,0,25)a.v[i]-=b.v[i];return a;
	}
	friend str&operator -=(str&a,const str&b){
		rep(i,0,25)a.v[i]-=b.v[i];return a;
	}
	friend str operator *(str a,int x){
		rep(i,0,25)a.v[i]*=x;return a;
	}
	friend bool operator <(const str&a,const str&b){
		return (a-b).count()<0;
	}
}ss[N*N],ct[N];
str init(const char*s){str a;
	for(int i=0;s[i];++i)++a.v[s[i]-'a'];return a;
}
string gt(int n){
	printf("? 1 %d\n",n);fflush(stdout);
	int m=n*(n+1)/2;str mx;
	rep(i,0,n-1)ct[i].clear();
	char tmp[N];
	rep(i,1,m){
		scanf("%s",tmp);
		ss[i]=init(tmp);
		mx=max(mx,ss[i]);
	}
	ct[0]=mx*(n+1);
	rep(i,1,m)ct[ss[i].count()]+=mx-ss[i];
	string ans;
	dep(i,n-1,n/2)rep(j,i+1,n-1)ct[i]-=ct[j]*(j-i+1);
	rep(i,n/2,n-1){
		int fl=(i==n/2)&&(n&1);
		rep(j,0,25){
			if(ct[i].v[j]&&!fl){
				ans=char(j+'a')+ans;fl=1;
				if(ct[i].v[j]>1)ans+=j+'a',fl=2;
			}else if(ct[i].v[j]&&fl==1)ans+=j+'a',fl=2;
		}
	}
	return ans;
}
int main(){int n;
	scanf("%d",&n);
	string s=gt(n),ans=s;
	if(n>1){
		if(n>3){
			int m=n/2;string s1=gt(m),s2=gt(m-1);char c;
			str tmp=init(s1.c_str())-init(s2.c_str());
			rep(i,0,25)if(tmp.v[i])c=i+'a';
			rep(i,0,m/2-1){int x=m-i-1;
				if(s1[x]!=(i?s2[x]:c))swap(s1[i],s1[x]);
				if(s2[i]!=s1[i])swap(s2[i],s2[m-i-2]);
			}
			rep(i,0,m-1)if(s[i]!=s1[i])swap(s[i],s[n-i-1]);
		}else{
			string tmp=gt(1);
			if(s[0]!=tmp[0])swap(s[0],s[n-1]);
		}
	}
	printf("! %s\n",s.c_str());fflush(stdout);
}