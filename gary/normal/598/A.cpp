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
LL Minus[50]={1};
int main(){
	rb(i,1,30){
		Minus[i]=Minus[i-1]*2;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		LL num;
		cin>>num;
		LL res=num*(num+1);
		res/=2;
		rb(i,0,30){
			if(Minus[i]>num) break;
			res-=Minus[i]*2;
		}
		cout<<res<<endl;
	}
	return 0;
}