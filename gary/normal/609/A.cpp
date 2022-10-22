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
bool cmp(int A,int B){
	return A>B;
}
int main(){
	int n,m;
	cin>>n>>m;
	int a[101];
	rb(i,1,n){
		cin>>a[i];
	}
	int res=0;
	sort(a+1,a+1+n,cmp);
	rb(i,1,n){
		if(m<=0) break;
		m-=a[i];
		res++;
	}
	cout<<res<<endl;
	return 0;
}