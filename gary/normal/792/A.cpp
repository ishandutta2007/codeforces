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
int a[200000+10];
map<int,LL> M; 
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	rb(i,1,n-1){
		M[abs(a[i]-a[i+1])]++;
		if(i+1!=n){
			M[abs(a[i]-a[n])]++;
		}
	}
	map<int,LL> :: IT ite=M.begin();
	cout<<ite->FIR<<" "<<ite->SEC<<endl;
	return 0;
}