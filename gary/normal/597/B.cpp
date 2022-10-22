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
mp a[500000+10];
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d %d",&a[i].SEC,&a[i].FIR);
	}
	sort(a+1,a+1+n);
	int res=0;
	int LAS=0;
	rb(i,1,n)
	{
		if(a[i].SEC>LAS){
			LAS=a[i].FIR;
			res++;
		}
		
	 } 
	cout<<res<<endl; 
	return 0;
}