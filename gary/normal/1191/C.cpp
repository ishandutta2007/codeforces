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
LL p[100000+10];
int main(){
	LL n,m,k;
	cin>>n>>m>>k;
	rb(i,1,m) scanf("%I64d",&p[i]);
	sort(p+1,p+1+m);
	int l=1;
	int minus=0;
	int res=0;
	while(l<=m){
//		cout<<l<<" "<<minus<<" "<<res<<endl;
		LL fir=l;
		LL now=(p[l]-minus)/k;
		now-=!(bool((p[l]-minus)%k));
		while(l<=m&&p[l]-minus<=(now+1)*k){
			l++;
		}
		minus+=l-fir;
		res++;
	}
	printf("%d\n",res);
	return 0;
}