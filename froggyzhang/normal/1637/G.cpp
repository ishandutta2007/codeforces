#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<int,int> > ans;
int cnt[50];
inline int Getr(int n){
	int p=1;
	while(p<n)p<<=1;
	return p;
}
inline int Getl(int n){
	int p=1;
	while((p<<1)<=n)p<<=1;
	return p;
}
void calc(int n,int B){
	if(n<1)return;
	int t=Getl(n*B);
	++cnt[__lg(t)+1];
	for(int i=t/B+1;i<=n;++i){
		++cnt[__lg(t<<1)+1];
		ans.emplace_back(i*B,(i-2*(i-t/B))*B);
	}
	calc(n-t/B,B<<1);
	calc(n-2*(n-t/B)-1,B);
}
void Solve(){
	cin>>n;
	if(n==2){
		cout<<-1<<'\n';
		return;
	}
	ans.clear();
	memset(cnt,0,sizeof(cnt));
	calc(n,1);
	int zz=Getr(n);
	int lim=__lg(zz)+1;
	while(true){
		bool emm=false;
		for(int i=1;i<lim;++i){
			if(cnt[i]&1&&cnt[0]){
				++cnt[i],--cnt[0];
				ans.emplace_back(0,1<<i-1);
				emm=true;
				break;
			}
			else if(cnt[i]>=2){
				cnt[i]-=2;
				++cnt[i+1],++cnt[0];
				ans.emplace_back(1<<i-1,1<<i-1);
				emm=true;
				break;
			}
		}
		if(!emm)break;
	}
	while(cnt[0]--)ans.emplace_back(0,zz);
	cout<<ans.size()<<'\n';
	for(auto [x,y]:ans){
		cout<<x<<' '<<y<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}