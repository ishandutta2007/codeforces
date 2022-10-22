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
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,d,y;
		cin>>n>>x>>y>>d;
		if(abs(x-y)%d==0){
			cout<<abs(x-y)/d<<endl;
			continue;
		}
		int res1=INF,res2=INF;
		if((n-y)%d==0){
			res1=(n-y)/d;
			res1+=ceil(double(n-x)/double(d));
		}
		if((y-1)%d==0){
			res2=(y-1)/d;
			res2+=ceil(double(x-1)/double(d));
		}
		res1=min(res1,res2);
		if(res1==INF)	cout<<-1<<endl;
		else cout<<res1<<endl;
	}
	return 0;
}