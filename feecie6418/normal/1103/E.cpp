#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
const int mod=998244353;
const ull inv5=14757395258967641293llu;
struct A{
	ull a[10];
	ull& operator [](int k){return a[k];}
	A(){memset(a,0,sizeof(a));} 
}a[100005];
int n;
A operator *(A x,A y){
	A z;
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)z[(i+j)%10]+=x[i]*y[j];
	return z;
}
A operator +(A x,A y){
	A z;
	for(int i=0;i<10;i++)z[i]=x[i]+y[i];
	return z;
}
A mulw(A x,int y){
	A z;
	for(int i=0;i<10;i++)z[(i+y)%10]=x[i];
	return z;
}
A Power(A x,int y){
	A r;
	r[0]=1;
	while(y){
		if(y&1)r=r*x;
		x=x*x,y>>=1;
	}
	return r;
}
void DFT(A a[],int n,int fl){
	for(int i=1;i<n;i*=10){
		for(int j=0;j<n;j+=10*i){
			for(int k=0;k<i;k++){
				A t[10];
				for(int l=0;l<10;l++)t[l]=a[l*i+j+k];
				for(int l=0;l<10;l++){
					A w;
					for(int p=0;p<10;p++)w=w+mulw(t[p],fl*l*p%10);
					a[l*i+j+k]=w;
				}
			}
		}
	}
}
ull Getv(A x){
	for(int i=9;i>=4;i--){
		for(int j=1;j<=4;j++)if(j&1)x[i-j]+=x[i];else x[i-j]-=x[i];
		x[i]=0;
	}
	return x[0];
}
int main(){
	scanf("%d",&n);
	for(int i=0,x;i<n;i++)scanf("%d",&x),a[x][0]++;
	DFT(a,100000,1);
	for(int i=0;i<100000;i++)a[i]=Power(a[i],n);
	DFT(a,100000,9);
	for(int i=0;i<n;i++){
		ull w=Getv(a[i]);
		for(int j=0;j<5;j++)w*=inv5;
		printf("%llu\n",(w>>5)%(1llu<<58));
	}
}