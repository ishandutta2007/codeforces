#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m;
int opt[N],l[N],r[N],x[N];
int die[N],know[N],lg[N];
set<int> S;
pair<int,int> f[N][20];
pair<int,int> Ask(int l,int r){
	if(l>r)return make_pair(0,0);
	int k=lg[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>opt[i];
		if(!opt[i]){
			cin>>l[i]>>r[i]>>x[i];
		}
		else{
			cin>>x[i];
		}
	}
	for(int i=1;i<=n;++i)die[i]=know[i]=m+1,S.insert(i);
	for(int i=1;i<=m;++i){
		if(opt[i]==0){
			if(x[i]==0){
				vector<int> jb;
				for(auto it=S.lower_bound(l[i]);it!=S.end()&&(*it)<=r[i];++it){
					jb.push_back(*it);
				}
				for(auto x:jb)S.erase(x),die[x]=i;
			}
		}
	}
	for(int i=1;i<=n;++i){
		f[i][0]=make_pair(die[i],i);
	}
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=m;++i){
		if(opt[i]==0){
			if(x[i]==1){
				auto [z,p]=Ask(l[i],r[i]);
				know[p]=min(know[p],max(i,max(Ask(l[i],p-1).first,Ask(p+1,r[i]).first)));
			}
		}
	}
	for(int i=1;i<=m;++i){
		if(opt[i]==1){
			int u=x[i];
			if(die[u]<=i){
				cout<<"NO\n";
			}
			else if(know[u]<=i){
				cout<<"YES\n";
			}
			else{
				cout<<"N/A\n";
			}
		}
	}
	return 0;
}