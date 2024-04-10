#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,nxt[100005],islst[100005],dif[100005],b[100005];
vector<int> vec[100005];
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),islst[b[i]]=1,vec[b[i]].push_back(i);
	for(int i=0;i<=n+1;i++){
		sort(vec[i].begin(),vec[i].end(),[](int x,int y){return islst[x]<islst[y];});
		for(int j=0;j+1<vec[i].size();j++){
			nxt[vec[i][j]]=vec[i][j+1];
		}
		if(vec[i].size()){
			nxt[i]=vec[i][0];
			dif[i]=1;
		}
	}
	int pos=0,cntle=0,cur=0;
	if(!nxt[pos])pos=n+1,cur=1;
	vector<int> ans;
	while(nxt[pos]){
		cur^=dif[pos];
		pos=nxt[pos],ans.push_back(pos);
		if(cur==0)cntle++;
	}
	cout<<cntle<<'\n';
	for(int i:ans)cout<<i<<' ';
	puts("");
	for(int i=0;i<=n+1;i++){
		nxt[i]=islst[i]=dif[i]=0,vec[i].clear(),b[i]=0;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}