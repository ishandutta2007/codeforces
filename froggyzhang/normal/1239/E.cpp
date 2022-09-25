#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
mt19937 rnd(time(0));
int n,c[N],mn,ans[N],qwq;
int calc(){
	static int pre[N],suf[N];
	sort(c+1,c+n+1);
	sort(c+n+1,c+(n<<1)+1,greater<int>());
	int mx=0;
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+c[i];
	for(int i=n;i>=1;--i)suf[i]=suf[i+1]+c[i+n];
	for(int i=1;i<=n;++i)mx=max(mx,pre[i]+suf[i]);
	return mx;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=(n<<1);++i){
		cin>>c[i];
	}
	memcpy(ans,c,sizeof(ans));
	qwq=1e9;
	while(1.0*clock()/CLOCKS_PER_SEC<=4.85){
		int res=150000;
		shuffle(c+1,c+(n<<1)+1,rnd);
		mn=calc();
		while(res--){
			int u,v;
			u=rnd()%n+1,v=rnd()%n+n+1;
			swap(c[u],c[v]);
			int tmp=calc();
			if(tmp<qwq){
				qwq=tmp;
				memcpy(ans,c,sizeof(ans));
			}
			if(tmp>mn||(tmp==mn&&rnd()&1))swap(c[u],c[v]);
			else mn=tmp;
		}
	}
	for(int i=1;i<=(n<<1);++i){
		cout<<ans[i]<<(i%n?' ':'\n');
	}
	return 0;
}