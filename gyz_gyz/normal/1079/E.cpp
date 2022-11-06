#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 20000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<double,double> pr;
int n,tot,ans,s[N];ll a[110][N];
void ck(){int al=0;
	rep(i,1,100)if(s[i])al++;
	if(al>2)return;
	if(al==2){
		rep(i,1,100)if(s[i]){
			if(s[i]*i*2==tot)return;
		}
	}
	printf("%d\n",n);exit(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);s[x]++;tot+=x;
	}
	a[0][0]=1;ck();
	rep(i,1,100)dep(t,n,1)dep(j,tot,1)rep(k,1,s[i])
		if(t>=k&&j-i*k>=0)a[t][j]+=a[t-k][j-i*k];
	rep(i,1,100)rep(j,1,s[i])if(a[j][i*j]==1)ans=max(ans,j);
	printf("%d\n",ans);
}