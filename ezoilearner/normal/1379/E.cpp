#include<bits/stdc++.h>
using namespace std;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
int h[Maxn],bel[Maxn],cnt;

int lowbit(int x){return x&(-x);}
bool check(int x,int y){return min(x,y)*2>max(x,y);}
int BT(int l,int r){
	if(l==r)return l;
	int mid=(l+r)>>1;
	cnt++;int t=cnt;
	h[BT(l,mid)]=t;h[BT(mid+1,r)]=t;
	return t;
}
int gao(int n){//cnt initial n
	if(n==lowbit(n))return BT(1,n); 
	int x=bel[n];
	if(!check(x,n-x))x>>=1;
	int t=gao(n-x);cnt++;h[t]=cnt;t=cnt;
	h[BT(n-x+1,n)]=t;
	return t;
}

int n,K;
void output(){
	puts("YES");
	for(int i=1;i<2*n;++i)printf("%d ",h[i]);puts("");
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
	rd(n);rd(K);
	if(n%2==0){
		puts("NO");
		return 0;
	}
	n=(n+1)>>1;cnt=n;
	for(int i=0,nxt;i<=16;++i){
		if(i==16)nxt=Maxn;
		else nxt=(1<<(i+1));
		for(int j=(1<<i);j<nxt;++j)bel[j]=(1<<i);
	}
	if(K==0){
		if(n!=lowbit(n))puts("NO");
		else{
			BT(1,n);
			output();
		}
		return 0;
	}
	if(K==1){
		if(n==lowbit(n))puts("NO");
		else{
			gao(n);
			output();
		}
		return 0;
	}
	int m=n-(K-1);
	if(m<3){
		puts("NO");
		return 0;
	}
	if(m!=lowbit(m)){
		int rt=gao(m);
		for(int i=m+1;i<=n;++i){
			cnt++;h[rt]=cnt;
			h[i]=cnt;rt=cnt;
		}
		output();
		return 0;
	}
	if(n==5&&K==2){
		puts("NO");
		return 0;
	}
	m--;
	int rt=gao(m);
	for(int i=m+1;i<n-1;++i){
		cnt++;h[i]=cnt;
		h[rt]=cnt;rt=cnt;
	}
	cnt++;h[rt]=cnt;rt=cnt;
	cnt++;h[n-1]=h[n]=cnt;h[cnt]=rt;
	output();
	return 0;
}