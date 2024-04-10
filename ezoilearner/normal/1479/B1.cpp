#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
const int N=100000;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
int A,B;
int tot[Maxn<<2];

int mx[Maxn],mn[Maxn],a[Maxn];

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
	rep(i,1,n)rd(a[i]);
	rep(i,0,n){
		mx[i]=-inf;
		mn[i]=inf;
	}
	int ad=0;
	mn[0]=1;mx[0]=1;tot[1+N]=1;
	A=1;B=1;
	rep(i,2,n){
		int tmp=(mn[a[i]],B+1)+ad,cur=A+ad;
		if(tot[A+N]>1||mx[a[i]]!=A)cur=A+1+ad;
		if(a[i]!=a[i-1])ad++;
		tmp-=ad;cur-=ad;
		int t=a[i-1];
		mn[t]=min(mn[t],tmp);B=min(B,tmp);
		A=max(A,cur);
		if(mx[t]!=-inf)tot[mx[t]+N]--;
		mx[t]=max(mx[t],cur);
		tot[mx[t]+N]++;
	}
	printf("%d\n",A+ad);
	return 0;
}