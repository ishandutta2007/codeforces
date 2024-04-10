#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n;
#define Maxn 1000010 
#define cout cerr
#define FR first
#define SE second
char ch[Maxn];
int a[Maxn];

void solve(){
	memset(a,0,sizeof(int)*(2*n+5));
	int s=n;
	rep(i,1,n){
		if(ch[i]=='1'){
			a[s]++;s++;
		}else{
			s--;a[s]++;
		}
	}
	int to=s;s=n;
	rep(i,1,n){
		int ty;
		if(a[s-1]>1)ty=1;
		else if(!a[s-1])ty=0;
		else if(to>=s||a[s])ty=0;
		else ty=1;
		if(ty){
			s--;a[s]--;
			ch[i]='0';
		}else{
			a[s]--;s++;
			ch[i]='1';
		}
	}
	printf("%s\n",ch+1);
}

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
	int T;rd(T);
	while(T--){
		scanf("%s",ch+1);n=strlen(ch+1);
		solve();
	}
	return 0;
}