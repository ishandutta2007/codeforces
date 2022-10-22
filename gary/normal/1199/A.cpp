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
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[100000+10];
int main(){
	int n,x,y;
	cin>>n>>x>>y;
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	priority_queue<mp, vector<mp>, greater<mp>> qian,hou;
	rb(i,2,min(n,y)){
		hou.push(II(a[i],i));
	}
	rb(i,1,n){
		
		if(i!=1) qian.push(II(a[i-1],i-1));
		if(i+y<=n){
			hou.push(II(a[i+y],i+y));
		}
		if(i>x+1)
		while(!qian.empty()&&qian.top().SEC<i-x){
			qian.pop();
		}
		while(!hou.empty()&&hou.top().SEC<=i){
			hou.pop();
		}
		int mini=INF;
		if(!qian.empty()) mini=qian.top().FIR;
		if(!hou.empty()) mini=min(mini,hou.top().FIR);
//		cout<<i<<" "<<mini<<endl;
		if(mini>a[i]){
			cout<<i<<endl;
			return 0;
		}
	}
	
	return 0;
}