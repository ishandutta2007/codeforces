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
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int h[200000+10];
int maxh=-INF;
int sum_h[200000+10];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	rb(i,1,n) scanf("%d",&h[i]),maxh=max(maxh,h[i]);
	sort(h+1,h+1+n);
	int end=n+1;
	int tot=0;
	rl(i,maxh,1){
		while(end>1&&h[end-1]>=i) end--;
		tot=n-end+1;
		sum_h[i]=tot;
	}
	int H=maxh+1;
	int res=0;
	while(1)
	{
		int tot=0;
		H--;
		if(H<=0) break;
		if(sum_h[H]==n) break;
		tot=sum_h[H];
		while(H>1&&tot+sum_h[H-1]<=k){
			H--;
			tot+=sum_h[H];
		}	
		res++;
	}
	printf("%d\n",res);
	return 0;
}