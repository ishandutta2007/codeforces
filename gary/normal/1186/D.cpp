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
int flag[100000+10];
double a[100000+10];
int main(){
	int n;
	cin>>n;
	int sum=0;
	rb(i,1,n){
		double num;
		cin>>num;
		a[i]=num;
		if(num==0) flag[i]=1;
		else{
			sum+=int (ceil(num));
//			v.PB(int(seil(num)));
		}
	}
//	cout<<sum<<endl;
	int NEED=sum;
	rb(i,1,n){
		if(ceil(a[i])==floor(a[i])){
			printf("%d\n",int(a[i]));
			continue;
		}
		double res=a[i];
		if(NEED>0){
			res=floor(a[i]);
			NEED--;	
		}
		else{
			res=ceil(a[i]);
		}
		int resres=int(res);
		printf("%d\n",resres);
	}
	return 0;
}