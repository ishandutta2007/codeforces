#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
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
vector<int> a;
int Solve(vector<int> &a,int h){
	if((int)a.size()<=2)return 0;
	vector<int> vec[2];
	for(auto x:a){
		int p=(x>>h)&1;
		vec[p].push_back(x);
	}
	int tot=0x3f3f3f3f;
	for(int i=0;i<2;++i){
		if(vec[i].empty())continue;
		tot=min(tot,Solve(vec[i],h-1)+max((int)vec[i^1].size()-1,0));
	}
	return tot;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a.push_back(read());
	}
	printf("%d\n",Solve(a,30));
	return 0;
}