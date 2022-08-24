#include<iostream>
using namespace std;
typedef long long ll;
int n;
char a[10000],b[10000];
char c[10000],d[10000],e[10000],f[10000];
int dif(char* u,char* v){
	int num=0;
	for(int i=0; i<n*n ;i++){
		if(u[i]!=v[i]) num++;
	}
	return num;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n*n ;i++){
		cin >> c[i];
		a[i]=i%2+'0';
		b[i]=1-(i%2)+'0';
	}
	for(int i=0; i<n*n ;i++) cin >> d[i];
	for(int i=0; i<n*n ;i++) cin >> e[i];
	for(int i=0; i<n*n ;i++) cin >> f[i];
	int ans=dif(c,a)+dif(d,a)+dif(e,b)+dif(f,b);
	ans=min(ans,dif(c,a)+dif(d,b)+dif(e,a)+dif(f,b));
	ans=min(ans,dif(c,a)+dif(d,b)+dif(e,b)+dif(f,a));
	ans=min(ans,dif(c,b)+dif(d,a)+dif(e,a)+dif(f,b));
	ans=min(ans,dif(c,b)+dif(d,a)+dif(e,b)+dif(f,a));
	ans=min(ans,dif(c,b)+dif(d,b)+dif(e,a)+dif(f,a));
	cout << ans << endl;
}