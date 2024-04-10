#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int n;
vector<int> al[100005];

ll best=0;

ii dfs(int i,int p){
	vector<ii> red;
	vector<ii> blue;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		ii temp=dfs(it,i);
		
		//cout<<it<<" "<<temp.first<<" "<<temp.second<<endl;
		
		red.push_back(ii(temp.first,it));
		blue.push_back(ii(temp.second,it));
	}
	
	sort(red.begin(),red.end());
	reverse(red.begin(),red.end());
	
	sort(blue.begin(),blue.end());
	reverse(blue.begin(),blue.end());
	
	//node itself is blue
	if (red.size()>=1) best=max(best,red[0].first+1);
	if (red.size()>=2) best=max(best,red[0].first+red[1].first+1);
	
	//node itself is red
	//children can be red or blue
	if (red.size()>=1) best=max(best,red[0].first+al[i].size()-1);
	if (red.size()>=2) best=max(best,red[0].first+red[1].first+al[i].size()-2);

	if (blue.size()>=1) best=max(best,blue[0].first+al[i].size()-1);
	if (blue.size()>=2) best=max(best,blue[0].first+blue[1].first+al[i].size()-2);

	if (red.size()>=1 && blue.size()>=1 && red[0].second!=blue[0].second) best=max(best,red[0].first+blue[0].first+al[i].size()-2);
	else{
		if (red.size()>=2 && blue.size()>=1) best=max(best,red[1].first+blue[0].first+al[i].size()-2);
		if (red.size()>=1 && blue.size()>=2) best=max(best,red[0].first+blue[1].first+al[i].size()-2);
	}
	
	if (red.empty()) return ii(0,1);
	else return ii(max(red[0].first,blue[0].first)+al[i].size()-2,red[0].first+1);
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin>>n;
	
	int a,b;
	for (int x=1;x<n;x++){
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	dfs(1,-1);
	
	cout<<best;
}