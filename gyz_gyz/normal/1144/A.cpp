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
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
bool v[26];
bool sol(){string s;
	rep(i,0,25)v[i]=0;cin>>s;
	for(auto i:s){
		if(v[i-'a'])return 0;
		v[i-'a']=1;
	}int x=0;
	rep(i,0,25)if(v[i]==1){
		if(x==2)return 0;x=1;
	}else if(x==1)x=2;
	return 1;
}
int main(){int t;
	scanf("%d",&t);
	while(t--)printf("%s\n",sol()?"Yes":"No");; 
}