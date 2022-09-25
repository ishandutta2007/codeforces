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
vector<pair<int,int> > E;
int n;
vector<int> Ask(int u){
	printf("? %d\n",u);
	fflush(stdout);
	vector<int> t(n+1);
	for(int i=1;i<=n;++i)t[i]=read();
	return t;
}
int main(){
	n=read();
	auto A=Ask(1);
	int cnt[2]={0,0};
	for(int i=1;i<=n;++i){
		++cnt[A[i]&1];	
	}
	if(cnt[0]<=cnt[1]){
		for(int i=1;i<=n;++i){
			if(!(A[i]&1)){
				vector<int> B;
				if(i^1)B=Ask(i);
				else B=A;
				for(int j=1;j<=n;++j){
					if(B[j]==1)E.emplace_back(i,j);	
				}	
			}	
		}
	}
	else{
		for(int i=1;i<=n;++i){
			if(A[i]&1){
				vector<int> B;
				B=Ask(i);
				for(int j=1;j<=n;++j){
					if(B[j]==1)E.emplace_back(i,j);
				}
			}
		}
	}
	printf("!\n");
	for(auto [x,y]:E){
		printf("%d %d\n",x,y);
	}
	fflush(stdout);
	return 0;
}