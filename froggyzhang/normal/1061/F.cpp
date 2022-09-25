#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,lev;
inline bool Ask(int x,int y,int z){
	cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
	string s;
	cin>>s;
	return s[0]=='Y';
}	
void Report(int x){
	cout<<"! "<<x<<endl;
	exit(0);	
}
mt19937 rnd(time(0));
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	int tmp=1;
	while(tmp*k<=n)++lev,tmp*=k;
	int x,y;
	vector<int> A;
	while(true){
		do{
			x=rnd()%n+1,y=rnd()%n+1;	
		}while(x==y);
		int cnt=0;
		A.clear();
		for(int i=1;i<=n;++i){
			if(i==x||i==y)continue;
			if(Ask(x,i,y))A.push_back(i),++cnt;	
		}
		if(cnt==lev*2-1)break;
	}
	for(auto u:A){
		int cnt=0;
		for(auto v:A){
			if(u==v)continue;
			cnt+=Ask(x,v,u);
		}	
		if(cnt==lev-1)Report(u);
	}
	return 0;
}