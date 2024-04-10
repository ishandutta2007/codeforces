#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef double db;
db c[2];
const int E=1e8;
int a[1005],n,m;
char s[1005];
mt19937_64 gen(time(0));
db mygen(){
	return (db)(gen()%E)/E;
}
int main(){
	cin >> n >> m;
	for (int i=0;i<m;i++){
        cin >> s;
        int mn=a[0];
        for (int j=0;j<n;j++) mn=min(mn,a[j]);
        c[0]=c[1]=0;
        for (int j=0;j<n;j++) c[s[j]-'0']+=exp((db)0.7*(mn-a[j]));
        if (mygen()<c[0]/(c[0]+c[1])) printf("0\n"); else printf("1\n");
        fflush(stdout);
        int x; cin >> x;
        for (int j=0;j<n;j++) if (x!=s[j]-'0') a[j]++;
	}
	return 0;
}