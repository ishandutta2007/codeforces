#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
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
LL x,y,z;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>x>>y>>z;
	cout<<(x+y)/z<<" ";
	LL rst1=x%z,rst2=y%z;
	LL NEED1=z-rst1,NEED2=z-rst2;
	if(rst2<NEED1&&rst1<NEED2){
		cout<<0;return 0;
	}
	if(rst2<NEED1){
		cout<<NEED2;return 0; 
	}
	if(rst1<NEED2 ){
		cout<<NEED1;
		return 0;
	}
	cout<<min(NEED1,NEED2);
	return 0;
}