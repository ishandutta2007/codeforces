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
	int n,k;
	scanf("%d %d",&n,&k);
	int a[2000];
	int can;
	can=(n&1)? 1:0;
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int res=0;
	rb(i,1,n){
//		if(i==n) break;
		if(a[i]==a[i+1]){
			res+=2;
			i++;
		}
		else
		if(can){
			res++;
			can--;
		}
		else{
			can++;
		}
	}
	cout<<res<<endl;
	return 0;
}