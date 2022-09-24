#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,a[200005],b[200005],pl[200005];
vector<int> pos[200005];
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
	}
	vector<int> s;
	for(int i=1;i<=n;i++)if(pos[i].size())s.push_back(i);
	sort(s.begin(),s.end(),[](int x,int y){return pos[x].size()>pos[y].size();});
	b[0]=0;
	while(s.size()){
		vector<int> vec;
		for(int i:s){
			b[++b[0]]=pos[i].back();
			pos[i].pop_back();
			if(pos[i].size())vec.push_back(i);
		}
		s=vec;
	}
	for(int i=1;i<=n;i++)pl[b[i]]=b[i%n+1];
	for(int i=1;i<=n;i++)cout<<a[pl[i]]<<' ';
	puts("");
	for(int i=1;i<=n;i++){
		a[i]=b[i]=pl[i]=0;
		pos[i].clear();
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}