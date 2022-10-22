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
mp a[100000+10];
mp each[100000+10];
LL res[100000+10];
int main(){
	int s,b;
	scanf("%d %d",&s,&b);
	rb(i,1,s) scanf("%d",&a[i].FIR),a[i].SEC=i;
	rb(i,1,b){
		int d,g;
		scanf("%d %d",&d,&g);
		each[i]=II(d,g);
	}
	sort(a+1,a+1+s);
	sort(each+1,each+b+1);
	int l=1;
	LL sum=0;
	rb(i,1,s){
		while(each[l].FIR<=a[i].FIR&&l<=b){
			sum+=each[l].SEC;
			l++;
		}
		res[a[i].SEC]=sum;
	}
	rb(i,1,s){
		printf("%I64d ",res[i]);
	}
	return 0;
}