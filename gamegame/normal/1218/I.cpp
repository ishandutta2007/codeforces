#include<bits/stdc++.h>
using namespace std;
typedef bitset<2000> row;
int n,k;
bool a[2000][2000],z[2000][2000];
bool r[2000],c[2000];
bool g[2000];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n ;i++){
		for(int j=0; j<n ;j++){
			char x;cin >> x;
			a[i][j]=x&1;
		}
	}
	for(int i=0; i<n ;i++){
		for(int j=0; j<n ;j++){
			char x;cin >> x;
			z[i][j]=x&1;
		}
	}
	for(int j=0; j<n ;j++){
		char x;cin >> x;
		g[j]=x&1;
	}
	int f=-1;
	for(int i=0; i<n ;i++){
		if(!g[i]) continue;
		f=i;break;
	}
	if(f==-1){
		for(int i=0; i<n ;i++) if(a[i]!=z[i]) return cout << "-1\n",0;
		return cout << "0\n",0;
	}
	c[f]=a[f][f]^z[f][f];
	for(int i=0; i<n ;i++){
		if(!g[i] || i==f) continue;
		c[i]=a[f][i]^z[f][i]^r[f];
		r[i]=a[i][f]^z[i][f]^c[f];
	}
	for(int i=0; i<n ;i++){
		if(g[i]) continue;
		c[i]=a[f][i]^z[f][i];
		r[i]=a[i][f]^z[i][f];
	}
	for(int i=0; i<n ;i++){
		for(int j=0; j<n ;j++){
			if(g[j]) a[i][j]^=r[i];
			if(g[i]) a[i][j]^=c[j];
			if(a[i][j]!=z[i][j]) return cout << "-1\n",0;
		}
	}
	int sum=0;
	for(int i=0; i<n ;i++){
		sum+=r[i];sum+=c[i];
	}
	cout << sum << endl;
	for(int i=0; i<n ;i++){
		if(r[i]) cout << "row " << i << '\n';
		if(c[i]) cout << "col " << i << '\n';
	}
}