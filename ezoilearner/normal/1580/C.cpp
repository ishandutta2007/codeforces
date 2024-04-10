#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

int n,m;
#define Maxn 200010
const int B=600;
int A[B+2][B+2];
int x[Maxn],y[Maxn],re[Maxn];
int sum[Maxn],S;
int At;
void go(int u,int ad){
	sum[u]+=ad;
	if(u<At)S+=ad;
}
void ADD(int u,int at,int ad){
	re[u]=at;
	if(x[u]+y[u]<=B){
		int z=x[u]+y[u];
		rep(i,0,x[u]-1)A[z][(at+i)%z]+=ad; 
	}else{
		while(at<=m){
			go(at,ad);
			if(at+x[u]>m)break;
			at+=x[u];
			go(at,-ad);
			at+=y[u];
		}
	}
}

int main(){
	rd(n);rd(m);
	rep(i,1,n){
		rd(x[i]);rd(y[i]);
	}
	int opt,k;int H=0;
	rep(i,1,m){
		At=i;
		rd(opt);rd(k);
		if(opt==1){H++;
			ADD(k,i,1);
		}else{H--;
			ADD(k,re[k],-1);
		}
		S+=sum[i];int res=S;
		rep(t,1,B)res+=A[t][i%t];
		printf("%d\n",H-res);
	}
	return 0;
}