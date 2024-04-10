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
int a[200000+10],b[200000+10];
map<int,int> M;
int main(){
	int n;
	cin>>n;
	rb(i,1,n){
		cin>>a[i];M[a[i]]=i;
	}
	rb(i,1,n){
		cin>>b[i];
		
	}
	int to=0;
	rb(i,1,n){
		if(M[b[i]]<to) {
			cout<<0<<" ";
		continue;
		}
		cout<<M[b[i]]-to<<" " ;
		to=M[b[i]];
	}
	return 0;
}