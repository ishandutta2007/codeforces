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
int tot=0;
vector<int> res; 
int main(){
	int n;
	scanf("%d",&n);
	int a[101];
	rb(i,1,n){
		scanf("%d",&a[i]);
		tot+=a[i];
	}
	res.PB(1);
	int res_tot=a[1];
	rb(i,2,n){
		if(a[i]*2<=a[1]){
			res_tot+=a[i];
			res.PB(i);
		}
	}
	if(res_tot*2<=tot){
		cout<<0<<endl;
	}
	else{
		cout<<res.size()<<endl;
		rb(i,1,res.size()){
			cout<<res[i-1]<<" "; 
		}
	}
	return 0;
}