#include<bits/stdc++.h>
using namespace std;
#define N 260
typedef long long ll;
int n,m,mp[N][N],tot,ans[N],myh[N];
typedef pair<int,int> pii;
const int Z[3][3]={
	{0,0,0},
	{0,1,2},
	{0,2,1}
};
vector<pii> OP(const vector<pii> &A,const vector<pii> &B,int mt){
	vector<pii> C;
	int j=0;
	for(int i=0;i<(int)A.size();++i){
		while(j<(int)B.size()&&B[j].first>A[i].first){
			C.emplace_back(B[j].first,(3-mt)*B[j].second%3);
			++j;
		}
		if(j<(int)B.size()&&B[j].first==A[i].first){
			if((A[i].second+(3-mt)*B[j].second)%3)C.emplace_back(B[j].first,(A[i].second+(3-mt)*B[j].second)%3);
			++j;
		}
		else{
			C.push_back(A[i]);
		}
	}
	while(j<(int)B.size()){
		C.emplace_back(B[j].first,(3-mt)*B[j].second%3);
		++j;
	}
	return C;
}
class Basis{
	vector<pii> d[N];
	int h[N];
public:
	Basis(){memset(h,0,sizeof(h));}
	bool Insert(vector<pii> V,int w){
		for(int i=tot;i>=0;--i){
			if(V.empty())break;
			if(V[0].first==i){
				if(d[i].empty()){
					d[i]=V;
					h[i]=w;
					return true;
				}
				int mt=Z[V[0].second][d[i][0].second];
				w=((w-mt*h[i])%3+3)%3;
				V=OP(V,d[i],mt);
			}
		}
		if(w)return false;
		return true;
	}
	void get_ans(int *ans){
		for(int i=1;i<=tot;++i){
			if(d[i].empty()){
				ans[i]=0;continue;
			}
			ans[i]=h[i];
			for(int j=1;j<(int)d[i].size();++j){
				int x=d[i][j].first,w=d[i][j].second;
				ans[i]=((ans[i]-ans[x]*w)%3+3)%3;
			}
			ans[i]=Z[ans[i]][d[i][0].second];
		}
	}
};
void Solve(){
	Basis B;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			mp[i][j]=-10;
		}
	}
	memset(ans,0,sizeof(ans));
	tot=0;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		if(w==-1){
			mp[u][v]=mp[v][u]=myh[i]=++tot;
		}
		else{
			--w;
			mp[u][v]=mp[v][u]=myh[i]=-w;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=j+1;k<=n;++k){
				if(mp[i][j]>=-2&&mp[i][k]>=-2&&mp[j][k]>=-2){
					vector<pii> V;
					int w=0;
					if(mp[i][j]<=0)w+=mp[i][j];
					else V.emplace_back(mp[i][j],1);
					if(mp[i][k]<=0)w+=mp[i][k];
					else V.emplace_back(mp[i][k],1);
					if(mp[j][k]<=0)w+=mp[j][k];
					else V.emplace_back(mp[j][k],1);
					w=(w%3+3)%3;
					if(V.empty()){
						if(w){
							cout<<-1<<'\n';
							return;
						}
					}
					else{
						sort(V.begin(),V.end(),greater<pii>());
						if(!B.Insert(V,w)){
							cout<<-1<<'\n';
							return;
						}
					}
				}
			}
		}
	}
	B.get_ans(ans);
	for(int i=1;i<=m;++i){
		cout<<(myh[i]<=0?-myh[i]+1:ans[myh[i]]+1)<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}