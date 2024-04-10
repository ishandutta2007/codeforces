#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 1000010
using namespace std;
int n,k,x,tot,a[N],s[N*30],t[N*30][2];long long ans;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)a[i]^=a[i-1];tot=1;
	rep(i,0,n){x=1;s[1]++;
		dep(j,29,0){
			bool c=(a[i]>>j)&1;
			if(!t[x][c])t[x][c]=++tot;
			x=t[x][c];s[x]++;
		}
	}
	rep(i,0,n){x=1;
		dep(j,29,0){
			bool c=((k^a[i])>>j)&1;
			if(!((k>>j)&1))ans+=s[t[x][!c]];
			if(t[x][c])x=t[x][c];else{x=0;break;}
		}
		ans+=s[x];
	}
	printf("%I64d\n",ans/2);
}