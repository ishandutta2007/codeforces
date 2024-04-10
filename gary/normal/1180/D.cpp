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
	int n,m;
	scanf("%d %d",&n,&m);
	int REST=n>>1;
	int RREST=n-(REST<<1);
	int upp=1,doww=n;
	rb(i,1,REST){	
		int l=1,r=m;
		rb(j,1,m){
			printf("%d %d\n%d %d\n",upp,l,doww,r);
			l++;
			r--;
		}
		upp++;
		doww--;
	}
	if(RREST){
		int now=REST+1;
		int l=1,r=m;
		rb(i,1,m){
			if(i&1)
			{
				printf("%d %d\n",now,l);
				l++;
				
			}
			else{
				printf("%d %d\n",now,r);
				r--;
			}
			
		}
	}
	return 0;
}