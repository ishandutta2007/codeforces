#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
#define y1 ysgh
int cx[N],cy[N],n,Q;
class BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
public:
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}Bx,By;
void Ins(int x,int y){
	if(!cx[x])Bx.Add(x,1);
	if(!cy[y])By.Add(y,1);
	++cx[x],++cy[y];
}
void Del(int x,int y){
	--cx[x],--cy[y];
	if(!cx[x])Bx.Add(x,-1);
	if(!cy[y])By.Add(y,-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	while(Q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,y;
			cin>>x>>y;
			Ins(x,y);
		}
		else if(opt==2){
			int x,y;
			cin>>x>>y;
			Del(x,y);
		}
		else{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			cout<<(Bx.Ask(x2)-Bx.Ask(x1-1)==x2-x1+1||By.Ask(y2)-By.Ask(y1-1)==y2-y1+1?"Yes\n":"No\n");
		}
	}
	return 0;
}