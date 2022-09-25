#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
char s[N];
int n;
void Solve(){
	cin>>(s+1);
	n=strlen(s+1);
	vector<int> mn(n+1),mx(n+1);
	vector<bitset<256> > msk(n+1);
	msk[0]=1;
	for(int i=1;i<=n;++i){
		mn[i]=mn[i-1]+(s[i]-'0');
		int x=0;
		for(int j=0;j<=min(3,i-1);++j){
			x+=(s[i-j]-'0')<<j;
			mx[i]=max(mx[i],mx[i-j-1]+x);
		}
		x=0;
		for(int j=0;j<=min(3,i-1);++j){
			x+=(s[i-j]-'0')<<j;
			msk[i]|=msk[i-j-1]<<(mx[i]-mx[i-j-1]-x);
		}
	}
	int w=mn[n];
	if(!w){
		cout<<-1<<'\n';
		return;
	}
	while((w&(w-1))||!msk[n][min(mx[n]-w,255)])++w;
	vector<pair<int,int> > ans;
	for(int i=n;i>=1;){
		int x=0;
		for(int j=0;j<=min(3,i-1);++j){
			x+=(s[i-j]-'0')<<j;
			if(w-x>=mn[i-j-1]&&w-x<=mx[i-j-1]&&msk[i-j-1][min(mx[i-j-1]-w+x,255)]){
				ans.emplace_back(i-j,i);
				i-=j+1;w-=x;
				break;
			}
		}
	}
	cout<<ans.size()<<'\n';
	reverse(ans.begin(),ans.end());
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