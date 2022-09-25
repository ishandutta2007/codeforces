#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
map<char,int> mp;
const char zyk[4]={'.','R','Y','B'};
int n,m;
class Basis{
	bitset<N> d[N];
	int vis[N];
public:
	bool Insert(bitset<N> x){
		for(int i=2*n;i>=1;--i){
			if(x[i]){
				if(!vis[i]){
					d[i]=x;vis[i]=1;return true;
				}
				else x^=d[i];
			}		
		}	
		return !x[n<<1|1];
	}
	bitset<N> get_ans(){
		bitset<N> A;
		for(int i=1;i<=2*n;++i){
			if(vis[i]){
				A[i]=((d[i]&A).count()&1)^d[i][n<<1|1];	
			}
		}
		return A;	
	}
}B;
int st[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	mp['R']=1,mp['Y']=2,mp['B']=3;
	mp['.']=mp['W']=0;
	for(int i=1;i<=n;++i){
		st[i]=1,st[i+n]=2;	
	}
	for(int i=1;i<=m;++i){
		string opt;
		int k;
		vector<int> P;
		cin>>opt>>k;
		P.resize(k);
		for(int j=0;j<k;++j)cin>>P[j];
		if(opt=="RY"){
			for(auto x:P)swap(st[x],st[x+n]);
		}
		else if(opt=="RB"){
			for(auto x:P)st[x+n]=st[x]^st[x+n];		
		}
		else if(opt=="YB"){
			for(auto x:P)st[x]=st[x]^st[x+n];
		}
		else{
			char C;
			cin>>C;
			int t[2]={mp[C]&1,mp[C]>>1&1};
			for(int i=0;i<2;++i){
				bitset<N> tmp;
				tmp[n<<1|1]=t[i];
				for(auto x:P){
					tmp[x]=st[x+i*n]&1;
					tmp[x+n]=st[x+i*n]>>1&1;
				}
				if(!B.Insert(tmp)){
					cout<<"NO\n";return 0;
				}
			}
		}
	}
	auto ans=B.get_ans();
	cout<<"YES\n";
	for(int i=1;i<=n;++i){
		cout<<zyk[ans[i+n]<<1|ans[i]];
	}
	return 0;
}