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
int a[100+10];
int final_res=INF;
int cpy[100+10];
int main(){
	int n;
	scanf("%d",&n);
	n*=2;
	rb(i,1,n){
		scanf("%d",&a[i]);
		cpy[i]=a[i];
	}
	int rest=n-2;
	int tmp_res=0;
//	cout<<rest<<endl;
	rb(i,1,n){
		rb(j,1,n){
			if(i==j) continue;
			tmp_res=0;
			a[i]=a[j]=INF;
			sort(a+1,a+1+n);
			rb(k,1,rest){
//				cout<<k<<endl;
				tmp_res+=a[k+1]-a[k];
				k++;
			}
			final_res=min(tmp_res,final_res);
			rb(k,1,n){
				a[k]=cpy[k];
			}
		}
	}
	printf("%d\n",final_res);
	return 0;
}