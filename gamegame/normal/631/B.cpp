#include<iostream>
using namespace std;
int main(){
ios::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	int a[n+1][m+1],b[n+1],c[n+1],d[m+1],e[m+1];
	for(int i=1; i<=n ;i++){
		b[i]=0;
		c[i]=-1;
	}
	for(int i=1; i<=m ;i++){
		d[i]=0;
		e[i]=-1;
	}
	int p,q,r;
	for(int i=1; i<=k ;i++){
		cin >> p >> q >> r;
		if(p==1){
			b[q]=r;
			c[q]=i;
		}
		else{
			d[q]=r;
			e[q]=i;
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(c[i]<e[j]){
				cout << d[j] << ' ';
			}
			else{
				cout << b[i] << ' ';
			}
		}
		cout << endl;
	}
}