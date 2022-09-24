#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
char a[1000005];
int n,suf[1000005];
vector<pr> Check(int sum){
	vector<pr> res;
	int cur=0,lst=0,s=0;
	for(int i=1;i<=n;i++){
		int ncur=cur*2+a[i]-'0';
		if(ncur+suf[i+1]+s>sum){
			res.push_back(pr(lst+1,i-1));
			s+=cur,lst=i-1,cur=a[i]-'0';
		}
		else cur=ncur;
	}
	s+=cur,res.push_back(pr(lst+1,n));
	if(s!=sum)return vector<pr>();
	return res;
}
void Solve(){
	scanf("%s",a+1),n=strlen(a+1),suf[n+1]=0;
	int cnt=0;
	for(int i=n;i;i--){
		suf[i]=suf[i+1]+(a[i]=='1');
		cnt+=a[i]=='1';
	}
	if(!cnt)return puts("-1"),void();
	int d=1;
	while(d<cnt)d<<=1;
	auto w=Check(d);
	if(w.size()){
		cout<<w.size()<<'\n';
		for(auto i:w)cout<<i.first<<' '<<i.second<<'\n';
		return ;
	}
	w=Check(d*2);
	if(w.size()){
		cout<<w.size()<<'\n';
		for(auto i:w)cout<<i.first<<' '<<i.second<<'\n';
		return ;
	}
	cout<<a+1<<endl;
	assert(0);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}