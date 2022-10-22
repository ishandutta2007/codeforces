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
int n;//the size of the array QAQ
int m;
int a[1003],b[1003];
pair<int,mp> r[1003];
int main(){
	scanf("%d %d",&n,&m);
	a[1]=n+3;
	rb(i,1,m){
		int ti,li,ri;
		scanf("%d %d %d",&ti,&li,&ri);
		li++;
		r[i]=II(ti,II(li,ri));
	}
	rb(i,1,n){
		b[i]=1;
	}
	int flag[1003]={0};
	rb(i,1,m){
		if(r[i].FIR==0) continue;
		rb(j,r[i].SEC.FIR,r[i].SEC.SEC) flag[j]=1;
	}
	rb(i,1,m){
		if(r[i].FIR==1) continue;
		int OK=0;
		rb(j,r[i].SEC.FIR,r[i].SEC.SEC){
			if(!flag[j]){
				OK=1;
				b[j]=-1;
				break;
			}
		}
		if(!OK){
			printf("NO\n");
			return 0;
		} 
	}
	printf("YES\n");
	printf("%d ",n+3);
	rb(i,2,n){
		printf("%d ",a[i]=a[i-1]+b[i]);
	}
	return 0;
}