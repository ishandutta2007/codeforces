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
LL M[11];
int main(){
	LL n,m;
	 cin>>n>>m;
	 rb(i,1,n){
	 	LL ai;
	 	cin>>ai;
	 	M[ai]++;
	 }
	 LL ANS=0;
	 rb(i,1,m){
	 	ANS+=M[i]*(n-M[i]);
	 }
	 cout<<ANS/2<<endl;
	return 0;
}