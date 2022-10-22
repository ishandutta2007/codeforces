//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int deep[200000+10],to[200000+10];
int len;
string s;
stack<int> tmp;
int best_deep[200000+10]; 
void dfs(int l,int r,int dep){
//	cout<<l<<" "<<r<<" "<<dep<<endl;
	deep[l]=dep;
	if(l==r-1) {
		best_deep[l]=dep;
		return;
	}
	int now=l+1;
	int MAX_=0;
	while(now<r-1){
		dfs(now,to[now],dep+1);
		MAX_=max(MAX_,best_deep[now]);
		now=to[now]+1;
	}
	best_deep[l]=MAX_;
}
int res[200000+10];
void recover(int l,int r,int dep){	//	cout<<l<<" "<<r<<" "<<dep<<" "<<best_deep[l]<<endl; 
	if(dep-1==best_deep[l]>>1){
		rb(i,l,r){
			res[i]=1;
		}
		return;
	}
	if(l==r-1){
		return;
	}
	int now=l+1;
	while(now<r-1){
		recover(now,to[now],dep+1);
		now=to[now]+1;
	}
}
int main(){
	scanf("%d",&len);
	cin>>s;
	rb(i,0,len-1){
		if(s[i]=='(') tmp.push(i);
		else{
			to[tmp.top()]=i;
			tmp.pop();
		}
	}
	int now=0;
	while(now<len-1){
		dfs(now,to[now],1);
		now=to[now]+1;
	}
	now=0;
	while(now<len-1){
		rb(i,now,to[now]){
			best_deep[i]=best_deep[now];
		}
		now=to[now]+1;
	}
	now=0;
//	cout<<best_deep[0]<<endl;
	while(now<len-1){
		recover(now,to[now],1);
		now=to[now]+1;
	}
	rb(i,0,len-1){
		printf("%d",res[i]);
	}
	return 0;
}