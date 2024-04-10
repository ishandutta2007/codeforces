#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void no(){ cout << "NO"; exit(0);}
constexpr int maxn = 540000;
char s[maxn], t[maxn];
int nxt[maxn];
void kmp(int n, char*a){
	int i,j;
	for(nxt[0]=j=-1,i=1;i<n;nxt[i++]=j){
		while(~j&&a[j+1]!=a[i])j=nxt[j];
		if(a[j+1]==a[i])j++;
	}	
}
int c[2];
int main(){
	ios::sync_with_stdio(false);
	cin >> s >> t;
	int n = strlen(t);
	kmp(n,t);
	int k=nxt[n-1];
	//cout << k;
	int m = strlen(s);
	for(int i = 0; i < m; i += 1) c[s[i] - '0'] += 1;
	for(int i = 0, j = 0; i < m; i += 1){
		if(not c[0]) cout << 1;
		else if(not c[1]) cout << 0;
		else{
			cout << t[j];
			c[t[j] - '0'] -= 1;
			if(j == n - 1) j = nxt[j];
			j += 1; 
		}
	}
}