#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
using namespace std;
int p1=1000000;
char buf[1000005];
int gc(){
	if(p1>=1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x;
}
int n;
void Solve(){
	n=rd();
	vector<pr> a(n);
	for(int i=0;i<n;i++)a[i].first=rd(),a[i].second=1;
	for(int i=1;a.size()>1;i++){
		vector<pr> b;
		for(int j=1;j<a.size();j++){
			b.push_back(pr(a[j].first-a[j-1].first,1));
		}
		if(a[0].first==0&&a[0].second>1)b.push_back(pr(0,a[0].second-1));
		sort(b.begin(),b.end(),greater<pr>());
		while(b.size()>=2&&b.back().first==0&&b[b.size()-2].first==0){
			b[b.size()-2].second+=b.back().second;
			b.pop_back();
		}
		reverse(b.begin(),b.end());
		a=b;
		//for(int i:b)cout<<i<<' ';
		//puts("");
	}
	cout<<a[0].first<<'\n';
}
int main(){
	int t=rd();
	while(t--)Solve();
}