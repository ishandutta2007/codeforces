#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
void Unique(auto &A){
	sort(A.begin(),A.end());
	A.erase(unique(A.begin(),A.end()),A.end());
}
vector<int> dfs(vector<int> s){
	if(s.size()==1)return s;
	vector<pair<int,int> > A,B;
	int m=s.size();
	for(int i=0;i<m;i+=2){
		A.emplace_back(s[i],s[i+1]);
		B.emplace_back(s[i+1],s[i]);
	}
	Unique(A),Unique(B);
	vector<int> l,r;
	for(int i=0;i<m;i+=2){
		auto tl=make_pair(s[i],s[i+1]);
		auto tr=make_pair(s[i+1],s[i]);
		l.push_back(lower_bound(A.begin(),A.end(),tl)-A.begin());
		r.push_back(lower_bound(B.begin(),B.end(),tr)-B.begin());
	}
	vector<int> cl=dfs(l),cr=dfs(r);
	vector<int> sl(m),sr(m);
	for(int i=0;i<m;i+=2){
		sl[i]=A[cl[i>>1]].first,sl[i+1]=A[cl[i>>1]].second;
		sr[i]=B[cr[i>>1]].first,sr[i+1]=B[cr[i>>1]].second;
	}
	return min(sl,sr);
}
string To_string(vector<int> v){
	string s="";
	for(auto c:v){
		s+=c+'a';
	}
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>s;
	vector<int> a(s.length());
	for(int i=0;i<1<<n;++i){
		a[i]=s[i]-'a';
	}
	cout<<To_string(dfs(a))<<'\n';
	return 0;
}