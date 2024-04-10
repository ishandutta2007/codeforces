#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
const int mod=998244353;
map<pair<int,int>,int> mp;
int g[2],n,m,Q,f1[N][2],f2[N][2],cnt1[2],cnt2[2],no1,no2,pw2[N];
void Ins(int x,int y,int w,int d){
	g[(x+y+w)&1]+=d;
	int &t1=f1[x][(y+w)&1];
	int &t2=f2[y][(x+w)&1];
	cnt1[(y+w)&1]-=!!t1;
	cnt2[(x+w)&1]-=!!t2;
	no1-=f1[x][0]&&f1[x][1];
	no2-=f2[y][0]&&f2[y][1];
	t1+=d,t2+=d;
	cnt1[(y+w)&1]+=!!t1;
	cnt2[(x+w)&1]+=!!t2;
	no1+=f1[x][0]&&f1[x][1];
	no2+=f2[y][0]&&f2[y][1];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	pw2[0]=1;
	for(int i=1;i<=1000000;++i){
		(pw2[i]=pw2[i-1]<<1)%=mod;
	}
	while(Q--){
		int x,y,opt;
		cin>>x>>y>>opt;
		auto t=make_pair(x,y);
		if(mp.count(t)){
			Ins(x,y,mp[t],-1);
			mp.erase(t);	
		}
		if(~opt){
			Ins(x,y,mp[t]=opt,1);
		}
		int ans=-!g[0]-!g[1];
		if(!no1)ans=(ans+pw2[n-cnt1[0]-cnt1[1]])%mod;
		if(!no2)ans=(ans+pw2[m-cnt2[0]-cnt2[1]])%mod;
		cout<<(ans+mod)%mod<<'\n';
	}
	return 0;
}