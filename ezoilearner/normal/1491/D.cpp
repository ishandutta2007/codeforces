#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

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

int q,u,v;

int a[40],b[40];
bool vis[40][40];
bool PD(){
	if(u>v)return false;
	int c1=0,c2=0;
	rep(i,0,29)if(u&(1<<i))a[++c1]=(1<<i);
	rep(i,0,29)if(v&(1<<i))b[++c2]=(1<<i);
	int l=c1+1,r=c1+1;
	per(i,c2,1){
		if(l>r)return false;
		while(r&&a[r-1]>b[i])r--;
		if(l>r)return false;
		l--;r--;int cur=b[i]-a[l];
		if(l<=0){
			l=1;
			if(l>r)return false;
			continue;
		}
		while(l>1&&cur>=a[l-1]){
			l--;cur-=a[l];
		}
	}
	return l==1;
}

int main(){
	int T;rd(T);
	while(T--){
		rd(u);rd(v);
		if(PD())puts("YES");
		else puts("NO");
	}
	return 0;
}