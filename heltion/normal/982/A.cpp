#include<bits/stdc++.h>
int main(){
	int n;
	scanf("%d", &n);
	char *s = new char[n + 1];
	scanf("%s", s);
	bool ans = true;
	for(int i = 0; i < n; i += 1){
		if(s[i] == '1')
			if(i and s[i - 1] == '1' or i < n - 1 and s[i + 1] == '1') ans = false;
		if(s[i] == '0')
			if((i == 0 or s[i - 1] == '0') and (i + 1 == n or s[i + 1] == '0'))
			ans = false;
	}
	printf(ans ? "Yes" : "No");
}