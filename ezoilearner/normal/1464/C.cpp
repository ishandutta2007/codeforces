#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n;ll T;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
char S[Maxn];
int sum[60];

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	cin>>n>>T;
	scanf("%s",S+1);
	rep(i,1,n-2){
		int t=S[i]-'a';
		T+=(1<<t);
		sum[t+1]++;
	}
	int t=S[n-1]-'a';T+=(1<<t);
	t=S[n]-'a';T-=(1<<t);
	if(T<0){
		puts("NO");
		return 0;
	}
	int a=0;
	rep(i,0,59){
		a+=sum[i];
		if(T&(1ll<<i))a--;
		if(a<0){
			puts("NO");
			return 0;
		}
		a/=2;
	}
	puts("YES");
	return 0;
}