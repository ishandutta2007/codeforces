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
	void read(){
		clear();char s[N];scanf("%s",s);
		for(int i=0;s[i];++i)++v[s[i]-'a'];
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
string gt(int n){
	int m=n*(n+1)/2;str mx;
	rep(i,0,n-1)ct[i].clear();
	rep(i,1,m)ss[i].read(),mx=max(mx,ss[i]);
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
	printf("? 1 %d\n",n);fflush(stdout);
	string s=gt(n),ans=s;
	if(n>1){
		printf("? 1 %d\n",n-1);fflush(stdout);
		string s1=gt(n-1);
		printf("? %d %d\n",n,n);fflush(stdout);
		string tmp=gt(1);
		rep(i,0,n/2-1){
			int x=n-i-1;
			if(s[x]!=(i?s1[x]:tmp[0]))swap(s[i],s[x]);
			if(s1[i]!=s[i])swap(s1[i],s1[n-i-2]);
		}
	}
	printf("! %s\n",s.c_str());fflush(stdout);
}