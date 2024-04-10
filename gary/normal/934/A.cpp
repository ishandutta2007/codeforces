#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
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
LL a[55],b[55];
pair<LL,LL> res[5000];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,n){
		scanf("%I64d",&a[i]);
	}
	rb(j,1,m){
		scanf("%I64d",&b[j]);
	}
	int tot=0;
	rb(i,1,n){
		rb(j,1,m){
			res[++tot].FIR=a[i]*b[j];
			res[tot].SEC=i;
		}
	}
	sort(res+1,res+1+tot);
//cout<<res[tot-1];
//	if(n==50&&m==50&&a[1]==1&&a[2]==6&&b[1]==1000000000){
//		cout<<endl<<tot<<endl<<res[tot];
//	}
//	LL tmpres=0;
	int now=tot-1;
	while(res[now].SEC==res[tot].SEC){
		now--;
	}
	cout<<res[now].FIR;
	return 0;
}