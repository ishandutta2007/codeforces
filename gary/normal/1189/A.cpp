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
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	if(n&1){
		cout<<1<<endl<<s;
		return 0;
	}
	int sum[101]={0};
	rb(i,1,n){
		sum[i]=sum[i-1]+(s[i-1]=='1'); 
	}
	if(sum[n]==n/2){
		cout<<2<<endl;
		rb(i,0,n-2){
			cout<<s[i];
		}
		cout<<" "<<s[n-1];
	}
	else{
		cout<<1<<endl<<s;
	}
	return 0;
}