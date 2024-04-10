#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
int d,e,f;
string s;
ll h[1000001][5];
ll p10[1000001][5];
ll p[5]={5123467,7654337,8357927,9876553,1000000007};
int num[200002];
bool check(int a,int b,int c){
	d=a,e=b,f=c;
	if(a<=0 || b<=0 || c<=0) return false;
	if(s[1]=='0' && a!=1 || s[a+1]=='0' && b!=1 || s[a+b+1]=='0' && c!=1) return false;
	for(int j=0; j<5 ;j++){
		ll num1=h[a][j],num2=h[a+b][j]-h[a][j]*p10[b][j]%p[j],num3=h[n][j]-h[a+b][j]*p10[c][j]%p[j];
		if((num3-num2-num1)%p[j]!=0) return false;
	}
	for(int i=0; i<=n ;i++){
		num[i]=0;
	}
	for(int i=1; i<=a ;i++){
		num[a-i]+=s[i]-48;
	}
	for(int i=a+1; i<=a+b ;i++){
		num[a+b-i]+=s[i]-48;
	}
	for(int i=n; i>a+b ;i--){
		num[n-i+1]+=num[n-i]/10;
		num[n-i]%=10;
		if(num[n-i]!=(s[i]-48)) return false;
	}
	for(int i=c; i<=n ;i++){
		if(num[i]!=0) return false;
	}
	return true;
}
void output(){
	for(int i=1; i<=d ;i++){
		cout << s[i];
	}
	cout << '+';
	for(int i=d+1; i<=d+e ;i++){
		cout << s[i];
	}
	cout << '=';
	for(int i=d+e+1; i<=n ;i++){
		cout << s[i];
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	n=s.size();
	s=' '+s;
	for(int j=0; j<5 ;j++) p10[0][j]=1;
	for(int i=1; i<=n ;i++){
		for(int j=0; j<5 ;j++){
			h[i][j]=(h[i-1][j]*10+s[i]-48)%p[j];
			p10[i][j]=p10[i-1][j]*10%p[j];
		}
	}
	for(int i=1; i<=n/2 ;i++){
		if(check(i-1,n-2*i+1,i)){
			output();
			return 0;
		}
		if(check(i,n-2*i,i)){
			output();
			return 0;
		}
		if(check(n-2*i,i,i)){
			output();
			return 0;
		}
		if(check(n-2*i+1,i-1,i)){
			output();
			return 0;
		}
	}
}