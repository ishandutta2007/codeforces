#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;;
string t;
multiset<string> s;
vector<string> v;
int main(){
	n=read();
	cout<<"? "<<1<<" "<<n<<endl;
	for(int i=1;i<=n*(n+1)/2;++i){
		cin>>t;
		sort(t.begin(),t.end());
		s.insert(t);
	}
	if(n==1){
		cout<<"! "<<(*s.begin())<<endl;
		return 0;
	}
	printf("? %d %d\n",2,n);
	for(int i=1;i<=n*(n-1)/2;++i){
		cin>>t;
		sort(t.begin(),t.end());
		s.erase(s.find(t));	
	}
	for(auto x:s)v.push_back(x);
	sort(v.begin(),v.end(),[&](string i,string j){return i.length()<j.length();});
	string ans="";
	for(auto t:v){
		for(int c=0;c<26;++c){
			int p0=0,p1=0;
			for(auto x:ans)p0+=x==(c+'a');
			for(auto x:t)p1+=x==(c+'a');
			if(p0^p1){ans+=c+'a';break;}
		}
	}
	cout<<"! "<<ans<<endl;
	return 0;
}