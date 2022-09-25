#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[10],n;
void Solve(){
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<10;++i)p[i]=0;
	vector<int> a;
	for(int i=0;i<n;++i){
		int c=s[i]-'0';
		if(c==1||c==4||c==6||c==8||c==9){cout<<1<<endl<<c<<endl;return;}
	}
	for(int i=0;i<n;++i){
		int c=s[i]-'0';
		if(p[c]){cout<<2<<endl<<11*c<<endl;return;}
		p[c]=1;
		a.push_back(c);
	}
	int m=a.size();
	int mn=23333,ans=0;
	for(int i=1;i<(1<<m);++i){
		int num=0;
		for(int j=0;j<m;++j){
			if(i>>j&1)num=num*10+a[j];
		}
		bool ok=false;
		for(int j=2;j*j<=num;++j){
			if(num%j==0){ok=true;break;}
		}
		if(ok){
			int cnt=__builtin_popcount(i);
			if(cnt<mn)mn=cnt,ans=num;
		}
	}
	cout<<mn<<endl<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}