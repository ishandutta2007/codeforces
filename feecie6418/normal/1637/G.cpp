#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,m,a[100005],pos[100005],done[100005];
pr ans[2000005];
bool Do(){
	bool fl=0;
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	//puts("");
	for(int i=1;i<=n;i++)pos[a[i]]=i,done[i]=0;
	for(int i=n;i>=1;i--){
		if(!done[i]&&(a[i]&-a[i])!=a[i]){
			int u=1;
			while(u<=a[i])u<<=1;
			ans[++m]={a[i],u-a[i]};
			int x=a[i],y=u-a[i],p=pos[u-a[i]];
			//cout<<a[i]<<' '<<p<<' '<<'\n';
			assert(a[p]==u-a[i]);
			pos[u-a[i]]--;
			a[i]=x+y,a[p]=abs(x-y);
			done[i]=done[p]=1;
			fl=1;
		}
	}
	return fl;
}
void Solve(){
	cin>>n;
	if(n==2)return puts("-1"),void();
	for(int i=1;i<=n;i++)a[i]=i;
	while(Do());
	int M=1;
	while(M<n)M<<=1;
	//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	//puts("");
	while(1){
		sort(a+1,a+n+1);
		set<int> p0;
		for(int i=1;i<=n;i++)if(!a[i])p0.insert(i);
		for(int i=2;i<=n;i++){
			if(!a[i])continue;
			if(a[i]==a[i-1]&&a[i]!=M&&!p0.size()){
				ans[++m]={a[i],a[i-1]};
				a[i]=2*a[i];
				a[i-1]=0;
				p0.insert(i-1);
			}
			if(a[i]!=M&&p0.size()){
				while(a[i]!=M){
					ans[++m]={a[i],0};
					ans[++m]={a[i],a[i]};
					a[i]=2*a[i];
				}
			}
		}
		bool fl=0;
		for(int i=1;i<=n;i++)if(a[i]!=M&&a[i]!=0)fl=1;
		//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
		//puts("");
		//system("pause");
		if(!fl){
			for(int i=1;i<=n;i++){
				if(a[i]==M){
					while(p0.size())ans[++m]={a[i],0},a[*p0.begin()]=M,p0.erase(p0.begin());
					break;
				}
			}
			break;
		}
	}
	cout<<m<<'\n';
	multiset<int> s;
	for(int i=1;i<=m;i++)cout<<ans[i].first<<' '<<ans[i].second<<'\n';
//	for(int i=1;i<=n;i++)s.insert(i);
//	for(int i=1;i<=m;i++){
//		if(s.find(ans[i].first)==s.end())assert(0);
//		s.erase(s.find(ans[i].first));
//		if(s.find(ans[i].second)==s.end())assert(0);
//		s.erase(s.find(ans[i].second));
//		s.insert(ans[i].first+ans[i].second);
//		s.insert(abs(ans[i].first-ans[i].second));
//	}
	//for(int i:s)cout<<i<<' ';
	//puts("");
	m=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}