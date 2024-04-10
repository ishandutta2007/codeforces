#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N],c[N],b[N];
string Ask(vector<pair<int,int> > A){
	if(A.empty())return "";
	cout<<"Q "<<A.size();
	for(auto [x,y]:A)cout<<' '<<x<<' '<<y;
	cout<<endl;
	string s;
	cin>>s;
	return s;	
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)a[i]=c[i]=b[i]=0;
	vector<pair<int,int> > A;
	A.clear();
	for(int i=1;i<n;i+=2)A.emplace_back(i,i+1);
	auto s=Ask(A);
	for(int i=1;i<n;i+=2){
		a[i]=s[i/2]-'0';
	}
	A.clear();
	for(int i=2;i<n;i+=2)A.emplace_back(i,i+1);
	s=Ask(A);
	for(int i=2;i<n;i+=2){
		a[i]=s[i/2-1]-'0';	
	}
	vector<int> p;
	for(int i=1;i<=n;++i){
		if(!a[i-1])p.push_back(i);
	}
	c[p[0]]=0;
	if(p.size()>1){
		c[p[1]]=1;
		A.clear();
		for(int i=0;i<(int)p.size();i+=4){
			if(i+2<(int)p.size())A.emplace_back(p[i],p[i+2]);
			if(i+3<(int)p.size())A.emplace_back(p[i+1],p[i+3]);
		}
		s=Ask(A);
		for(int i=0,j=0;i<(int)p.size();i+=4){
			if(i+2<(int)p.size())b[p[i]]=s[j++]-'0';
			if(i+3<(int)p.size())b[p[i+1]]=s[j++]-'0';
		}
		A.clear();
		for(int i=2;i<(int)p.size();i+=4){
			if(i+2<(int)p.size())A.emplace_back(p[i],p[i+2]);
			if(i+3<(int)p.size())A.emplace_back(p[i+1],p[i+3]);
		}
		s=Ask(A);
		for(int i=2,j=0;i<(int)p.size();i+=4){
			if(i+2<(int)p.size())b[p[i]]=s[j++]-'0';
			if(i+3<(int)p.size())b[p[i+1]]=s[j++]-'0';
		}
		for(int i=0;i<(int)p.size()-2;++i){
			if(b[p[i]])c[p[i+2]]=c[p[i]];
			else c[p[i+2]]=c[p[i]]^c[p[i+1]]^3;	
		}
	}
	int cnt[3]={0,0,0};
	for(int i=1;i<=n;++i){
		if(a[i])c[i+1]=c[i];
		++cnt[c[i]];	
	}
	cout<<"A "<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<'\n';
	for(int i=1;i<=n;++i){
		if(c[i]==0)cout<<i<<' ';
	}
	cout<<'\n';
	for(int i=1;i<=n;++i){
		if(c[i]==1)cout<<i<<' ';
	}
	cout<<'\n';
	for(int i=1;i<=n;++i){
		if(c[i]==2)cout<<i<<' ';
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();	
	}
	return 0;
}