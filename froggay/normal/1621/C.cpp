#include<bits/stdc++.h>
using namespace std;
#define N 23333
typedef long long ll;
int n,p[N];
inline int Ask(int x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)p[i]=-1;
	for(int i=1;i<=n;++i){
		if(p[i]==-1){
			vector<int> c;
			while(true){
				int t=Ask(i);
				if(c.empty()||t^c[0])c.push_back(t);
				else break;
			}
			for(int j=0;j<c.size();++j){
				p[c[j]]=c[(j+1)%c.size()];
			}
		}
	}
	cout<<"! ";
	for(int i=1;i<=n;++i){
		cout<<p[i]<<" ";
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}