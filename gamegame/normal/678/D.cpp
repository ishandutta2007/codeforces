#include<iostream>
using namespace std;
long long mod(long long a){
	return a%((long long)1e9+7);
}
long long power(long long x,long long y){//x^y%1e9+7
	long long int a[62];
	a[0]=x;
	for(int i=1; i<=61 ;i++){
		a[i]=mod(a[i-1]*a[i-1]);
	}
	long long ans=1;
	for(int i=0; i<=61 ;i++){
		if(y&1){
			ans=mod(ans*a[i]);
		}
		y>>=1;
	}
	return ans;
}
long long int divide(long long int num,long long int den){
    long long int a,b,c,d,e,f;
    a=1e9+7;
    c=1;
    e=0;
    b=den;
    while(b!=0){
        c=c-a/b*e;
        a=a%b;
        swap(a,b);
        swap(c,e);
    }
    c=c%den;
    c=(c+den)%den;
    c*=(den-num%den);
    c%=den;
    num=c*(1e9+7)+num;
    num=num/den;
    num=mod(num);
    return num;
}
int main(){
	long long a,b,n,x;
	cin >> a >> b >> n >> x;
	if(a==1) cout << mod(x+mod(n)*b);
	else cout << mod(mod(power(a,n)*x)+mod(divide(power(a,n)-1,a-1)*b));
}