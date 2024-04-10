#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,Q,a[N];
void Solve(){
	unordered_map<int,vector<int> > mp[30];
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		int x=0;
		for(int j=29;j>=0;--j){
			x|=a[i]&(1<<j);
			mp[j][x].push_back(i);
		}
	}
	cin>>Q;
	while(Q--){
		int l,r;
		cin>>l>>r;
		int u=0;
		vector<int> tmp;
		for(int i=29;i>=0;--i){
			int cnt=upper_bound(mp[i][u].begin(),mp[i][u].end(),r)-lower_bound(mp[i][u].begin(),mp[i][u].end(),l);
			int zz=cnt;
			for(auto z:tmp){
				cnt+=!(z>>i&1);
			}
			if(cnt>=2){
				vector<int> _tmp;
				for(auto z:tmp){
					if(!(z>>i&1))_tmp.push_back(z);
				}
				tmp=_tmp;
			}
			else{
				if(zz){
					int p=*lower_bound(mp[i][u].begin(),mp[i][u].end(),l);
					tmp.push_back(a[p]);
				}
				u|=1<<i;
			}
		}
		cout<<u<<'\n';
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