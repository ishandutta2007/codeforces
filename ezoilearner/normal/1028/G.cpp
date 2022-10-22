#include<bits/stdc++.h>
using namespace std;
const int N=10000;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

#define Maxn 10005
#define cout cerr
#define FR first
#define SE second

ll A[Maxn];
ll base[5];
ll F[6][Maxn];

int query(int len){
	printf("%d ",len);
	rep(i,1,len)printf("%lld ",A[i]);
	puts("");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	if(x==-2)exit(0);
	if(x==-1)exit(0);
	else return x+1;
}

ll To(int t,ll x){
	if(x<=N)return F[t][x];
	return base[t];
}

void solve(ll L,ll R,int t){
	ll at=L+To(t-1,L);
	int len=min(L,10000ll);
	A[0]=L-1;A[len+1]=R+1;
	rep(i,1,len){
		A[i]=at;
		at+=1+To(t-1,at+1);
	}
	at=query(len);
	solve(A[at-1]+1,A[at]-1,t-1);
}

int main(){
	base[0]=0;
	rep(i,1,4)base[i]=base[i-1]*10001ll+10000ll;
	rep(t,0,4)
		rep(i,1,N){
			ll at=i+F[t][i];
			rep(j,1,i){
				if(at>=N){
					at+=(base[t]+1)*(i-j+1);
					break;
				}
				at+=1+F[t][at+1];
			}
			F[t+1][i]=at-i;
		}
	solve(1,10004205361450474ll,5);
	return 0;
}