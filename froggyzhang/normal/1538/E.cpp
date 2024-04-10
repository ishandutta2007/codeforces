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
int T,n;
struct Data{
	ll t;
	string L,R;	
	Data(){t=0;L=R="";}
};
map<string,Data> mp;
void Solve(){
	mp.clear();
	n=read();
	while(n--){
		string A,opt,B,C;
		cin>>A;
		cin>>opt;
		if(opt[0]==':'){
			cin>>B;
			mp[A].t=0;
			for(int i=0;i<=(int)B.length()-4;++i){
				mp[A].t+=(B.substr(i,4)=="haha");
			}
			mp[A].L=(int)B.length()<=3?B:B.substr(0,3);
			mp[A].R=(int)B.length()<=3?B:B.substr((int)B.length()-3,3);	
		}
		else{
			cin>>B;
			cin>>opt;
			cin>>C;
			auto x=mp[B];
			auto y=mp[C];
			string tmp=x.R+y.L;
			mp[A].t=x.t+y.t;
			for(int i=0;i<=(int)tmp.length()-4;++i){
				mp[A].t+=(tmp.substr(i,4)=="haha");	
			}
			if((int)x.L.length()==3)mp[A].L=x.L;
			else if(x.L.length()+y.L.length()>=3)mp[A].L=x.L+y.L.substr(0,3-(int)x.L.length());
			else mp[A].L=x.L+y.L;
			if((int)y.R.length()==3)mp[A].R=y.R;
			else if(x.R.length()+y.R.length()>=3)mp[A].R=x.R.substr((int)x.R.length()-(3-(int)y.R.length()),3-(int)y.R.length())+y.R;
		}
		if(!n){
			printf("%lld\n",mp[A].t);	
		}
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}