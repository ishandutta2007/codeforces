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
int n;
vector<pair<int,int> > vec[2];
inline void Out(int b,int i,int j){
	printf("%d %d %d\n",b,i,j);
	fflush(stdout);	
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			vec[(i+j)&1].push_back(make_pair(i,j));
		}
	}
	for(int i=1;i<=n*n;++i){
		int x=read();
		if(x==1){
			if(!vec[1].empty())Out(2,vec[1].back().first,vec[1].back().second),vec[1].pop_back();
			else Out(3,vec[0].back().first,vec[0].back().second),vec[0].pop_back();
		}
		else if(x==2){
			if(!vec[0].empty())Out(1,vec[0].back().first,vec[0].back().second),vec[0].pop_back();
			else Out(3,vec[1].back().first,vec[1].back().second),vec[1].pop_back();
		}
		else if(x==3){
			if(!vec[0].empty())Out(1,vec[0].back().first,vec[0].back().second),vec[0].pop_back();
			else Out(2,vec[1].back().first,vec[1].back().second),vec[1].pop_back();
		}	
	}
	return 0;
}