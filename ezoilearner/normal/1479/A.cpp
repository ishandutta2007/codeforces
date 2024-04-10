#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

#define Maxn
#define cout cerr
#define FR first
#define SE second
int ask(int p){
	printf("? %d\n",p);fflush(stdout);
    int x;scanf("%d",&x);return x;
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
	int n;rd(n);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(ask(mid)>ask(mid+1))l=mid+1;
		else r=mid;
	}
	printf("! %d\n",r);fflush(stdout);
	return 0;
}