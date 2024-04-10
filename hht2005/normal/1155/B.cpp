    #include<bits/stdc++.h>
    using namespace std;
    char s[100010];
    int main() {
    	int n,cnt=0;
    	scanf("%d%s",&n,s);
    	for(int i=0;i<=n-11;i++)
    		if(s[i]=='8')cnt++;
    	if(cnt<=(n-11)/2)puts("NO");
    	else puts("YES");
    	return 0;
    }