#include<bits/stdc++.h>
#define maxn 55

using namespace std;
char s[maxn];
int n,ans;

bool check(int x,int y){
	for (int i=x;i<=y;i++) if (s[i]!=s[x+y-i]) return false;
	return true;
}

int main(){
	cin >> s;
	n=strlen(s);
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++)
			if (!check(i,j)) ans=max(ans,j-i+1);
	cout << ans << endl;
	return 0;
}