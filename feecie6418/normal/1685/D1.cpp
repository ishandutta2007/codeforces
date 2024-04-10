#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,p[205],vst[205];
int Calc(vector<int> t){
	int sum=0;
	for(int i=0;i<t.size();i++)sum+=abs(t[i]-p[t[(i+1)%t.size()]]);
	return sum;
}
void Solve(){
	vector<int> ans;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++){
		if(vst[i])continue;
		int x=i;
		vst[x]=1;
		vector<int> loops;
		loops.push_back(i);
		while(!vst[p[x]])x=p[x],vst[x]=1,loops.push_back(x);
		int mn=1e9;
		vector<int> o;
		for(int j=0;j<=ans.size();j++){
			vector<int> tmp=ans;
			for(int k:loops)tmp.insert(tmp.begin()+j,k);
			// 
			if(Calc(tmp)<mn)mn=Calc(tmp),o=tmp;
		}
		ans=o;
	}
	for(int i:ans)cout<<i<<' ';
	puts("");
	for(int i=1;i<=n;i++)vst[i]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve(); 
}